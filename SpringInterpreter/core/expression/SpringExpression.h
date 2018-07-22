#ifndef SPRINGEXPRESSION_H
#define SPRINGEXPRESSION_H
#include "SpringBaseExpression.h"

#include <deque>

namespace spr {

    class SpringIDExpression;
    class SpringIDListExpression;
    class SpringConstantExpression;
    class SpringListDefinitionExpression;
    class SpringObjectDefinitionExpression;
    class SpringFunctionCallExpression;
    class SpringOperatorExpression;
    class SpringNewExpression;
    class SpringArrowExpression;
    class SpringPointExpression;
    class SpringSubscriptExpression;
    class SpringParagraph;
    class SpringExpressionList;

    /***********************************************************************
    SpringArrowExpression
    ***********************************************************************/

    class SpringArrowExpression : public SpringBaseExpression{
    public:
        SpringArrowExpression(SpringIDExpression* o, SpringBaseExpression*e);
        virtual ~SpringArrowExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;

    private:
        SpringIDExpression* objectId = nullptr;
        SpringBaseExpression* expression = nullptr;
    };

    /***********************************************************************
    SpringListDefinitionExpression
    ***********************************************************************/

    class SpringListDefinitionExpression : public SpringBaseExpression
    {
    public:
        SpringListDefinitionExpression(SpringExpressionList* e = nullptr);
        virtual ~SpringListDefinitionExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;

    private:
        SpringExpressionList* expList = nullptr;
    };

    /***********************************************************************
    SpringObjectDefinitionExpression
    ***********************************************************************/

    class SpringObjectDefinitionExpression : public SpringBaseExpression
    {
    public:
        SpringObjectDefinitionExpression(SpringParagraph* p = nullptr);
        virtual ~SpringObjectDefinitionExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;

    private:
        SpringParagraph* body = nullptr;
    };

    /***********************************************************************
    SpringFunctionCallExpression
    ***********************************************************************/

    class SpringFunctionCallExpression : public SpringBaseExpression
    {
    public:
        SpringFunctionCallExpression(SpringBaseExpression* f, SpringExpressionList* e = nullptr);
        virtual ~SpringFunctionCallExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment & env) override;

    private:
        SpringBaseExpression *func = nullptr;
        SpringExpressionList * expList = nullptr;
    };

    /***********************************************************************
    SpringConstantExpression
    ***********************************************************************/

    class SpringConstantExpression : public SpringBaseExpression
    {
    public:
        SpringConstantExpression();
        SpringConstantExpression(bool b);
        SpringConstantExpression(int n);
        SpringConstantExpression(double d);
        SpringConstantExpression(char * c);
        SpringConstantExpression(SpringBaseExpression * a, SpringParagraph * b);
        SpringConstantExpression(SpringParagraph * b);
        virtual ~SpringConstantExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;

    private:
        enum SpringConstantType{
            NIL_TYPE,
            BOOL_TYPE,
            INT_TYPE,
            DOUBLE_TYPE,
            STRING_TYPE,
            FUNC_TYPE
        };

        SpringConstantType constType = NIL_TYPE;
        bool bValue = false;
        int iValue = 0;
        double dValue = 0.0;
        std::string sValue = "";
        SpringIDListExpression * funcArgs = nullptr;
        SpringParagraph * funcBody = nullptr;
    };

    /***********************************************************************
    SpringIDListExpression
    ***********************************************************************/

    class SpringIDListExpression : public SpringBaseExpression
    {
    public:
        SpringIDListExpression();
        SpringIDListExpression(SpringIDExpression * id);
        virtual ~SpringIDListExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;

        void checkSyntax();
        void add_front(SpringIDExpression * id);
        unsigned size();
        int getNondefaultArgumentNum();
        std::vector<std::string> getAllSymbols();
        SpringIDExpression * at(unsigned id);
        SpringIDExpression * operator[](unsigned id);

    private:
        std::deque<SpringIDExpression *> idList;
    };

    /***********************************************************************
    SpringIDExpression
    ***********************************************************************/

    class SpringIDExpression : public SpringBaseExpression
    {
    public:
        SpringIDExpression(char * id);
        SpringIDExpression(char * id, SpringBaseExpression* d);
        virtual ~SpringIDExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;
        virtual void set(SpringRuntimeEnvironment & env, const SpringObjectPtr & p) override;
        virtual bool isLeftValue() override;

        std::string getName();
        bool hasDefaultValue();
        SpringObjectPtr getDefaultValue(SpringRuntimeEnvironment & env);

    private:
        std::string name = "";
        SpringBaseExpression* defaultValue = nullptr;
    };

    /***********************************************************************
    SpringSubscriptExpression
    ***********************************************************************/

    class SpringSubscriptExpression : public SpringBaseExpression
    {
    public:
        SpringSubscriptExpression(SpringBaseExpression * l, SpringBaseExpression * s);
        virtual ~SpringSubscriptExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;
        virtual void set(SpringRuntimeEnvironment & env, const SpringObjectPtr & p) override;
        virtual bool isLeftValue() override;

    private:
        SpringBaseExpression * targetList = nullptr;
        SpringBaseExpression * startIdx = nullptr;
    };

    /***********************************************************************
    SpringOperatorExpression
    ***********************************************************************/

    class SpringOperatorExpression : public SpringBaseExpression
    {
    public:
        SpringOperatorExpression();
        SpringOperatorExpression(int t, SpringBaseExpression *l);
        SpringOperatorExpression(int t, SpringBaseExpression *l, SpringBaseExpression *r);
        SpringOperatorExpression(int t, SpringBaseExpression *l, SpringBaseExpression *m, SpringBaseExpression *r);
        virtual ~SpringOperatorExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment & env) override;

    protected:
        int nodeType = -1;
        SpringBaseExpression *leftTree = nullptr;
        SpringBaseExpression *midTree = nullptr;
        SpringBaseExpression *rightTree = nullptr;
    };

    /***********************************************************************
    SpringPointExpression
    ***********************************************************************/

    class SpringPointExpression : public SpringBaseExpression
    {
    public:
        SpringPointExpression(SpringBaseExpression *l, SpringIDExpression *r);
        virtual ~SpringPointExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment & env) override;
        virtual void set(SpringRuntimeEnvironment &env, const SpringObjectPtr &value) override;
        virtual bool isLeftValue() override;

    private:
        SpringBaseExpression *leftTree = nullptr;
        SpringIDExpression *rightTree = nullptr;
    };

    /***********************************************************************
    SpringNewExpression
    ***********************************************************************/

    class SpringNewExpression : public SpringBaseExpression
    {
    public:
        SpringNewExpression(SpringIDExpression *i);
        virtual ~SpringNewExpression() override;
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &env) override;

    private:
        SpringIDExpression *classId = nullptr;
    };

}


#endif // SPRINGEXPRESSION_H
