#ifndef SPRINGSTANDARDTYPE_H
#define SPRINGSTANDARDTYPE_H

#include <vector>
#include <memory>
#include <map>
#include <functional>

#include "SpringObject.h"

namespace spr {

    /***********************************************************************
    SpringNil
    ***********************************************************************/

    class __declspec(dllexport) SpringNil : public SpringObject
    {
    public:
        virtual SpringObjectPtr size(SpringRuntimeEnvironment &env) override;
        virtual std::string getPrintString() override;

    private:
        SpringNil();
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringBool
    ***********************************************************************/

    class __declspec(dllexport) SpringBool : public SpringObject
    {
    public:
        virtual SpringObjectPtr add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr opposite(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr increment(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr decrement(SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalNot(SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseComplement(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual std::string getPrintString() override;
        virtual bool        toBool() override;
        virtual int         toInt() override;
        virtual double      toDouble() override;
        virtual std::string toString() override;

    private:
        bool value = false;
        SpringBool();
        SpringBool(bool b);
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringInt
    ***********************************************************************/

    class __declspec(dllexport) SpringInt : public SpringObject{
    public:
        virtual SpringObjectPtr add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr opposite(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr increment(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr decrement(SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalNot(SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseComplement(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual bool        toBool() override;
        virtual int         toInt() override;
        virtual double      toDouble() override;
        virtual std::string toString() override;

        virtual std::string getPrintString() override;

    private:
        int value = 0;
        SpringInt();
        SpringInt(const int &i);
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringDouble
    ***********************************************************************/

    class __declspec(dllexport) SpringDouble : public SpringObject
    {
    public:
        virtual SpringObjectPtr add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr opposite(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr increment(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr decrement(SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalNot(SpringRuntimeEnvironment &env) override;

        virtual std::string getPrintString() override;
        virtual bool        toBool() override;
        virtual int         toInt() override;
        virtual double      toDouble() override;
        virtual std::string toString() override;

    private:
        double value = 0.0;
        SpringDouble();
        SpringDouble(double d);
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringString
    ***********************************************************************/

    class __declspec(dllexport) SpringString : public SpringObject
    {
    public:
        virtual SpringObjectPtr add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr opposite(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr getItem(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual void setItem(const SpringObjectPtr &index, const SpringObjectPtr &value, SpringRuntimeEnvironment &env) override;
        virtual void delItem(const SpringObjectPtr &index, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr size(SpringRuntimeEnvironment &env) override;
        virtual std::string getPrintString() override;
        virtual bool        toBool() override;
        virtual int         toInt() override;
        virtual double      toDouble() override;
        virtual std::string toString() override;

    private:
        std::string value = "";
        SpringString();
        SpringString(const std::string &s);
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringMatrix
    ***********************************************************************/

    class __declspec(dllexport) SpringMatrix : public SpringObject
    {
    public:
        virtual SpringObjectPtr size(SpringRuntimeEnvironment &env) override;
        virtual std::string getPrintString() override;

    private:
        SpringMatrix();
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringList
    ***********************************************************************/

    class __declspec(dllexport) SpringList : public SpringObject
    {
    public:
        virtual SpringObjectPtr add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr opposite(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr getItem(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual void setItem(const SpringObjectPtr &index, const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual void delItem(const SpringObjectPtr &index, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr newInstance(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr size(SpringRuntimeEnvironment &env) override;
        virtual std::string getPrintString() override;
        virtual void getPtr(std::vector<SpringObjectPtr> &ptrList) override;
        virtual void getRelatedPtr(std::set<SpringObjectPtr> &ptrList) override;

        virtual SpringListPtr toListPointer() override;

        void append(SpringObjectPtr objPtr);
        void insert(int i, SpringObjectPtr p);
        void set(int i, SpringObjectPtr p);
        void remove(int i);
        void clear();
        unsigned getLength();
        SpringObjectPtr operator[](int i);
        SpringObjectPtr at(int i);
        std::vector<SpringObjectPtr> getAll();

    private:
        std::vector<SpringObjectPtr> value;
        SpringList();
        SpringList(const std::vector<SpringObjectPtr> &l);
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringFunction
    ***********************************************************************/

    typedef std::function<SpringObjectPtr(const std::vector<SpringObjectPtr>&, SpringRuntimeEnvironment&)> SpringStandardFunctionType;
    class SpringIDListExpression;
    class SpringParagraph;
    class SpringRuntimeEnvironment;
    class SpringStruct;
    class __declspec(dllexport) SpringFunction : public SpringObject
    {
    public:
        virtual SpringObjectPtr call(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env) override;
        virtual std::string getPrintString() override;
        virtual void getPtr(std::vector<SpringObjectPtr> &ptrList) override;
        virtual void getRelatedPtr(std::set<SpringObjectPtr> &ptrList) override;
        virtual SpringFunctionPtr toFunctionPointer() override;

        void setSelf(const SpringObjectPtr &s);

    private:
        bool isStandardFunction = false;
        SpringObjectPtr self = nullptr;
        SpringIDListExpression * inputParam = nullptr;
        SpringParagraph * body = nullptr;
        SpringStandardFunctionType stdFunction;
        std::string funcDescription = "";

        SpringFunction(SpringIDListExpression *i, SpringParagraph *b);
        SpringFunction(const SpringStandardFunctionType &f, const std::string &d);
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringStruct
    ***********************************************************************/

    class __declspec(dllexport) SpringStruct : public SpringObject
    {
    public:
        virtual SpringObjectPtr add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr opposite(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr increment(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr decrement(SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr logicalNot(SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseComplement(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr size(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr newInstance(SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr call(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env) override;

        virtual SpringObjectPtr getItem(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;
        virtual SpringObjectPtr getAttribute(const std::string &key, SpringRuntimeEnvironment &env) override;
        virtual void setAttribute(const std::string &key, const SpringObjectPtr &other, SpringRuntimeEnvironment &) override;
        virtual void setPrototype(const SpringObjectPtr &other, SpringRuntimeEnvironment &env) override;

        virtual std::string getPrintString() override;
        virtual void getPtr(std::vector<SpringObjectPtr> &ptrList) override;
        virtual void getRelatedPtr(std::set<SpringObjectPtr> &ptrList) override;
        virtual SpringStructPtr toStructPointer() override;

        void addMember(const std::string &key, SpringObjectPtr p);
        bool existMember(const std::string &key);
        SpringObjectPtr getMember(const std::string &key);

    private:
        const std::string PROTOTYPE_KEY = "__proto__";
        std::map<std::string, SpringObjectPtr> members;
        SpringStruct();
        SpringStruct(const std::map<std::string, SpringObjectPtr> &s);
        friend class SpringObjectManager;
    };

    /***********************************************************************
    SpringVoidPointer
    ***********************************************************************/

    class __declspec(dllexport) SpringAny : public SpringObject
    {
    public:
        virtual void* toPointer(const std::string &c) override;
        virtual std::string getPrintString() override;

    private:
        void *ptr = nullptr;
        std::string className = "";
        SpringAny(void *p, const std::string &c);
        friend class SpringObjectManager;
    };

}

#endif // SPRINGSTANDARDTYPE_H
