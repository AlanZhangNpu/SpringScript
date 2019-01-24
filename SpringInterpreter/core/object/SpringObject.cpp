#include "SpringObject.h"
#include "SpringStandardType.h"
#include "Spring.h"
#include "./core/expression/SpringExpression.h"

#define SPR_THROW_UNKNOWN_OP1(x) SpringException::throwUnknownOperatorException(x, {this->getType()});\
return env.ojbManager->create();

#define SPR_THROW_UNKNOWN_OP2(x) SpringException::throwUnknownOperatorException(x, {this->getType(), other->getType()});\
return env.ojbManager->create();


namespace spr {

    SpringObject::SpringObject()
    {}

    SpringObject::~SpringObject()
    {}

    /***********************************************************************
    type related functions
    ***********************************************************************/

    bool SpringObject::isNil()
    {
        return type == SPR_NIL;
    }

    bool SpringObject::isBool()
    {
        return type == SPR_BOOL;
    }

    bool SpringObject::isInt()
    {
        return type == SPR_INT;
    }

    bool SpringObject::isDouble()
    {
        return type == SPR_DOULBE;
    }

    bool SpringObject::isString()
    {
        return type == SPR_STRING;
    }

    bool SpringObject::isMatrix()
    {
        return type == SPR_MATRIX;
    }

    bool SpringObject::isList()
    {
        return type == SPR_LIST;
    }

    bool SpringObject::isStruct()
    {
        return type == SPR_STRUCT;
    }

    bool SpringObject::isFunction()
    {
        return type == SPR_FUNCTION;
    }

    bool SpringObject::isPointer()
    {
        return type == SPR_POINTER;
    }

    SpringObject::SpringObjectType SpringObject::getType()
    {
        return type;
    }

    std::string SpringObject::getTypeString()
    {
        return typeToString(type);
    }

    bool SpringObject::checkType(char t)
    {
        switch (t) {
        case 'n': return isNil();
        case 'b': return isBool();
        case 'i': return isInt();
        case 'd': return isDouble();
        case 's': return isString();
        case 'l': return isList();
        case 'm': return isMatrix();
        case 't': return isStruct();
        case 'f': return isFunction();
        case 'p': return isPointer();
        case 'c': return type == SPR_CPP_OBJECT;
        default:  return false;
        }
    }

    std::string SpringObject::typeToString(const SpringObjectType &t)
    {
        switch (t) {
        case SPR_NIL:               return "nil";
        case SPR_BOOL:              return "bool";
        case SPR_INT:               return "int";
        case SPR_DOULBE:            return "double";
        case SPR_STRING:            return "string";
        case SPR_MATRIX:            return "matrix";
        case SPR_LIST:              return "list";
        case SPR_STRUCT:            return "struct";
        case SPR_FUNCTION:          return "function";
        case SPR_POINTER:           return "pointer";
        case SPR_CPP_OBJECT:        return "cpp object";
        default:                    return "nil";
        }
    }

    /***********************************************************************
    value related functions
    ***********************************************************************/

//    void SpringObject::unbox(bool &p)
//    {
//        p = toBool();
//    }

//    void SpringObject::unbox(int &p)
//    {
//        p = toInt();
//    }

//    void SpringObject::unbox(double &p)
//    {
//        p = toDouble();
//    }

//    void SpringObject::unbox(std::string &p)
//    {
//        p = toString();
//    }

    template<typename T>
    void SpringObject::to(T &value)
    {
        if(std::is_same<typename std::decay<T>::type, bool>::value){
            value = toBool();
        }else if(std::is_same<typename std::decay<T>::type, int>::value){
            value = toInt();
        }else if(std::is_same<typename std::decay<T>::type, double>::value){
            value = toDouble();
        }else if(std::is_same<typename std::decay<T>::type, std::string>::value){
            value = toString();
        }
    }

    /***********************************************************************
    value related virtual functions
    ***********************************************************************/

    bool SpringObject::toBool()
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to bool");
        return 0;
    }

    int SpringObject::toInt()
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to int");
        return 0;
    }

    double SpringObject::toDouble()
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to float");
        return 0.0;
    }

    std::string SpringObject::toString()
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to string");
        return std::string();
    }

    SpringListPtr SpringObject::toListPointer()
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to list");
        return dynamic_cast<SpringList*>(this);
    }

    SpringFunctionPtr SpringObject::toFunctionPointer()
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to function");
        return dynamic_cast<SpringFunction*>(this);
    }

    SpringStructPtr SpringObject::toStructPointer()
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to object");
        return dynamic_cast<SpringStruct*>(this);
    }

    void *SpringObject::toPointer(const std::string &)
    {
        SpringException::throwRuntimeError("TypeError: unable to convert " + getTypeString() + " to pointer");
        return nullptr;
    }

    /***********************************************************************
    virtual operator functions
    ***********************************************************************/

    SpringObjectPtr SpringObject::add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("+")
    }

    SpringObjectPtr SpringObject::increment(SpringRuntimeEnvironment &env)
    {
        SpringException::throwUnknownOperatorException("++", {this->getType()});
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringObject::subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SpringException::throwUnknownOperatorException("-", {this->getType(), other->getType()});
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringObject::decrement(SpringRuntimeEnvironment &env)
    {
        SpringException::throwUnknownOperatorException("--", {this->getType()});
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringObject::opposite(SpringRuntimeEnvironment &env)
    {
        SpringException::throwUnknownOperatorException("-", {this->getType()});
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringObject::multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SpringException::throwUnknownOperatorException("*", {this->getType(), other->getType()});
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringObject::power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SpringException::throwUnknownOperatorException("**", {this->getType(), other->getType()});
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringObject::divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("/")
    }

    SpringObjectPtr SpringObject::mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("%")
    }

    SpringObjectPtr SpringObject::greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2(">")
    }

    SpringObjectPtr SpringObject::greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2(">=")
    }

    SpringObjectPtr SpringObject::less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("<")
    }

    SpringObjectPtr SpringObject::lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("<=")
    }

    SpringObjectPtr SpringObject::equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("==")
    }

    SpringObjectPtr SpringObject::notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("!=")
    }

    SpringObjectPtr SpringObject::logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("&&")
    }

    SpringObjectPtr SpringObject::logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("||")
    }

    SpringObjectPtr SpringObject::logicalNot(SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP1("!")
    }

    SpringObjectPtr SpringObject::bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("&")
    }

    SpringObjectPtr SpringObject::bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("|")
    }

    SpringObjectPtr SpringObject::bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("^")
    }

    SpringObjectPtr SpringObject::bitwiseComplement(SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP1("~")
    }

    SpringObjectPtr SpringObject::bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("<<")
    }

    SpringObjectPtr SpringObject::bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2(">>")
    }

    SpringObjectPtr SpringObject::size(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(1);
    }

    SpringObjectPtr SpringObject::newInstance(SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP1("new")
    }

    SpringObjectPtr SpringObject::call(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP1("()")
    }

    bool SpringObject::checkType(const std::vector<SpringObjectPtr> &args,
                                 const std::initializer_list<std::string> &patterns)
    {
        if(args.size() == 0 && patterns.size() == 0)
            return true;

        for(std::string item : patterns){
            unsigned itemLen = item.length();
            if(args.size() != itemLen)
                continue;
            bool correct = true;
            for(unsigned i = 0; i < itemLen; i++){
                char t = item[i];
                if(!(args[i]->checkType(t))){
                    correct = false;
                    break;
                }
            }
            if(correct)
                return true;
        }
        return false;
    }

    void SpringObject::getPtr(std::vector<SpringObjectPtr> &ptrList)
    {
        ptrList.push_back(this);
    }

    void SpringObject::getRelatedPtr(std::set<SpringObjectPtr> &ptrList)
    {
        ptrList.insert(this);
    }

    std::string SpringObject::getPrintString()
    {
        return getTypeString();
    }

    SpringObjectPtr SpringObject::getItem(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        SPR_THROW_UNKNOWN_OP2("[]")
    }

    void SpringObject::setItem(const SpringObjectPtr &index, const SpringObjectPtr &, SpringRuntimeEnvironment &)
    {
        SpringException::throwUnknownOperatorException("[]", {this->getType(), index->getType()});
    }

    void SpringObject::delItem(const SpringObjectPtr &index, SpringRuntimeEnvironment &)
    {
        SpringException::throwUnknownOperatorException("[]", {this->getType(), index->getType()});
    }

    SpringObjectPtr SpringObject::getAttribute(const std::string &key, SpringRuntimeEnvironment &env)
    {
        SpringException::throwNoAttributeException(key);
        return env.ojbManager->create();
    }

    void SpringObject::setAttribute(const std::string &key, const SpringObjectPtr &, SpringRuntimeEnvironment &)
    {
        SpringException::throwNoAttributeException(key);
    }

    void SpringObject::setPrototype(const SpringObjectPtr &, SpringRuntimeEnvironment &)
    {
        SpringException::throwUnknownOperatorException("->", {this->getType()});
    }

}
