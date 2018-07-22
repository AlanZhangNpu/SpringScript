#ifndef SPRINGOBJECT_H
#define SPRINGOBJECT_H

#include <string>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <functional>

namespace spr {

    class SpringObject;
    class SpringNil;
    class SpringBool;
    class SpringInt;
    class SpringDouble;
    class SpringString;
    class SpringMatrix;
    class SpringList;
    class SpringStruct;
    class SpringFunction;
    class SpringVoidPointer;

    class SpringIDListExpression;
    class SpringParagraph;
    class SpringRuntimeEnvironment;

    typedef SpringObject*       SpringObjectPtr;
    typedef SpringNil*          SpringNilPtr;
    typedef SpringBool*         SpringBoolPtr;
    typedef SpringInt*          SpringIntPtr;
    typedef SpringDouble*       SpringDoublePtr;
    typedef SpringString*       SpringStringPtr;
    typedef SpringMatrix*       SpringMatrixPtr;
    typedef SpringList*         SpringListPtr;
    typedef SpringFunction*     SpringFunctionPtr;
    typedef SpringStruct*       SpringStructPtr;
    typedef SpringVoidPointer*  SpringVoidPointerPtr;

    class __declspec(dllexport) SpringObject
    {
    public:
        virtual ~SpringObject();

        enum SpringObjectType{
            SPR_NIL,
            SPR_BOOL,
            SPR_INT,
            SPR_DOULBE,
            SPR_STRING,
            SPR_MATRIX,
            SPR_LIST,
            SPR_STRUCT,
            SPR_FUNCTION,
            SPR_CPP_OBJECT,
            SPR_POINTER
        };

        bool isNil();
        bool isBool();
        bool isInt();
        bool isDouble();
        bool isString();
        bool isMatrix();
        bool isList();
        bool isStruct();
        bool isFunction();
        bool isPointer();
        bool checkType(char t);
        SpringObjectType getType();
        std::string getTypeString();

        // type conversions
        void unbox(bool &p);
        void unbox(int &p);
        void unbox(double &p);
        void unbox(std::string &p);

        virtual bool                toBool();
        virtual int                 toInt();
        virtual double              toDouble();
        virtual std::string         toString();
        virtual SpringListPtr       toListPointer();
        virtual SpringFunctionPtr   toFunctionPointer();
        virtual SpringStructPtr     toStructPointer();
        virtual void*               toPointer(const std::string &);

        // operators
        virtual SpringObjectPtr add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr opposite(SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr increment(SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr decrement(SpringRuntimeEnvironment &env);

        virtual SpringObjectPtr greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);

        virtual SpringObjectPtr logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr logicalNot(SpringRuntimeEnvironment &env);

        virtual SpringObjectPtr bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr bitwiseComplement(SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env);

        virtual SpringObjectPtr size(SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr newInstance(SpringRuntimeEnvironment &env);
        virtual SpringObjectPtr call(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env);

        virtual SpringObjectPtr getItem(const SpringObjectPtr &index, SpringRuntimeEnvironment &env);
        virtual void setItem(const SpringObjectPtr &index, const SpringObjectPtr &, SpringRuntimeEnvironment &);
        virtual void delItem(const SpringObjectPtr &index, SpringRuntimeEnvironment &);

        virtual SpringObjectPtr getAttribute(const std::string &, SpringRuntimeEnvironment &env);
        virtual void setAttribute(const std::string &, const SpringObjectPtr &, SpringRuntimeEnvironment &);
        virtual void setPrototype(const SpringObjectPtr &, SpringRuntimeEnvironment &);

        virtual void getPtr(std::vector<SpringObjectPtr> &ptrList);
        virtual void getRelatedPtr(std::set<SpringObjectPtr> &ptrList);
        virtual std::string getPrintString();

        // static functions
        static bool checkType(const std::vector<SpringObjectPtr> &args, const std::initializer_list<std::string> &patterns);
        static std::string typeToString(const SpringObjectType &t);

    protected:
        SpringObjectType type = SPR_CPP_OBJECT;
        SpringObject();
        friend class SpringObjectManager;
    };

}
#endif // SPRINGOBJECT_H
