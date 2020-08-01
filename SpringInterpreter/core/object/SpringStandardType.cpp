#include "SpringStandardType.h"

#include <iostream>
#include <math.h>
#include <algorithm>

#include "Spring.h"
#include "./core/statement/SpringParagraph.h"
#include "./core/expression/SpringExpression.h"

#define binaryOperator(op) SpringObjectPtr operatorFunc = getMember(op); \
if(!operatorFunc->isFunction()) \
    SpringException::throwUnknownOperatorException(op, {getType(), other->getType()}); \
return operatorFunc->call({other}, env);

#define unaryOperator(op) SpringObjectPtr operatorFunc = getMember(op); \
if(!operatorFunc->isFunction()) \
    SpringException::throwUnknownOperatorException(op, {getType()}); \
return operatorFunc->call({}, env);

namespace spr {

    /***********************************************************************
    SpringNil
    ***********************************************************************/

    SpringNil::SpringNil()
    {
        type = SPR_NIL;
    }

    std::string SpringNil::getPrintString()
    {
        return "nil";
    }

    SpringObjectPtr SpringNil::size(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(0);
    }

    /***********************************************************************
    SpringBool
    ***********************************************************************/

    SpringBool::SpringBool() :
        value(false)
    {
        type = SPR_BOOL;
    }

    SpringBool::SpringBool(bool b) :
        value(b)
    {
        type = SPR_BOOL;
    }

    SpringObjectPtr SpringBool::add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() + other->toInt());

        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() + other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("+", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::increment(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(this->toInt() + 1);
    }

    SpringObjectPtr SpringBool::decrement(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(this->toInt() - 1);
    }

    SpringObjectPtr SpringBool::subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() - other->toInt());

        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() - other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("-", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::opposite(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(-(this->toInt()));
    }

    SpringObjectPtr SpringBool::multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() * other->toInt());

        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() * other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("*", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create((int)(pow(this->toInt(), other->toInt())));
        case SPR_DOULBE:
            return env.ojbManager->create(pow(this->toDouble(), other->toDouble()));
        default:
            break;
        }
        return SpringObject::power(other, env);
    }

    SpringObjectPtr SpringBool::divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() / other->toInt());

        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() / other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("/", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() % other->toInt());

        default:
            SpringException::throwUnknownOperatorException("%", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() > other->toDouble());

        default:
            SpringException::throwUnknownOperatorException(">", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() >= other->toDouble());

        default:
            SpringException::throwUnknownOperatorException(">=", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() < other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("<", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() <= other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("<=", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() == other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("?=", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() != other->toDouble());

        default:
            SpringException::throwUnknownOperatorException("!=", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toBool() && other->toBool());

        default:
            SpringException::throwUnknownOperatorException("&&", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toBool() || other->toBool());

        default:
            SpringException::throwUnknownOperatorException("||", {this->getType(), other->getType()});
            break;
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr SpringBool::logicalNot(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(!(this->toBool()));
    }

    SpringObjectPtr SpringBool::bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() & other->toInt());
        }
        return SpringObject::bitwiseAnd(other, env);
    }

    SpringObjectPtr SpringBool::bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() | other->toInt());
        }
        return SpringObject::bitwiseOr(other, env);
    }

    SpringObjectPtr SpringBool::bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() ^ other->toInt());
        }
        return SpringObject::bitwiseXor(other, env);
    }

    SpringObjectPtr SpringBool::bitwiseComplement(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(~(this->toInt()));
    }

    SpringObjectPtr SpringBool::bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() << other->toInt());
        }
        return SpringObject::bitwiseShiftLeft(other, env);
    }

    SpringObjectPtr SpringBool::bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() >> other->toInt());
        }
        return SpringObject::bitwiseShiftRight(other, env);
    }

    std::string SpringBool::getPrintString()
    {
        return value ? "true" : "false";
    }

    bool SpringBool::toBool()
    {
        return value;
    }

    int SpringBool::toInt()
    {
        return value ? 1 : 0;
    }

    double SpringBool::toDouble()
    {
        return value ? 1.0 : 0.0;
    }

    std::string SpringBool::toString()
    {
        return std::to_string(value);
    }

    /***********************************************************************
    SpringInt
    ***********************************************************************/

    SpringInt::SpringInt() :
        value(0)
    {
        type = SPR_INT;
    }

    SpringInt::SpringInt(const int &i) :
        value(i)
    {
        type = SPR_INT;
    }

    SpringObjectPtr SpringInt::add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() + other->toInt());
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() + other->toDouble());
        default:
            break;
        }
        return SpringObject::add(other, env);
    }

    SpringObjectPtr SpringInt::subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() - other->toInt());
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() - other->toDouble());
        default:
            break;
        }
        return SpringObject::subtract(other, env);
    }

    SpringObjectPtr SpringInt::opposite(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(-(this->toInt()));
    }

    SpringObjectPtr SpringInt::multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() * other->toInt());
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() * other->toDouble());
        default:
            break;
        }
        return SpringObject::multiply(other, env);
    }

    SpringObjectPtr SpringInt::power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create((int)(pow(this->toInt(), other->toInt())));
        case SPR_DOULBE:
            return env.ojbManager->create(pow(this->toDouble(), other->toDouble()));
        default:
            break;
        }
        return SpringObject::power(other, env);
    }

    SpringObjectPtr SpringInt::divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() / other->toInt());
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() / other->toDouble());
        default:
            break;
        }
        return SpringObject::divide(other, env);
    }

    SpringObjectPtr SpringInt::mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
            return env.ojbManager->create(this->toInt() % other->toInt());
        default:
            break;
        }
        return SpringObject::mod(other, env);
    }

    SpringObjectPtr SpringInt::increment(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(this->toInt() + 1);
    }

    SpringObjectPtr SpringInt::decrement(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(this->toInt() - 1);
    }

    SpringObjectPtr SpringInt::greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() > other->toDouble());
        default:
            break;
        }
        return SpringObject::greater(other, env);
    }

    SpringObjectPtr SpringInt::greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() >= other->toDouble());
        default:
            break;
        }
        return SpringObject::greaterEqual(other, env);
    }

    SpringObjectPtr SpringInt::less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() < other->toDouble());
        default:
            break;
        }
        return SpringObject::less(other, env);
    }

    SpringObjectPtr SpringInt::lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() <= other->toDouble());
        default:
            break;
        }
        return SpringObject::lessEqual(other, env);
    }

    SpringObjectPtr SpringInt::equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() == other->toDouble());
        default:
            break;
        }
        return SpringObject::equal(other, env);
    }

    SpringObjectPtr SpringInt::notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() != other->toDouble());
        default:
            break;
        }
        return SpringObject::notEqual(other, env);
    }

    SpringObjectPtr SpringInt::logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toBool() && other->toBool());
        default:
            break;
        }
        return SpringObject::logicalAnd(other, env);
    }

    SpringObjectPtr SpringInt::logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toBool() || other->toBool());
        default:
            break;
        }
        return SpringObject::logicalOr(other, env);
    }

    SpringObjectPtr SpringInt::logicalNot(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(!(this->toBool()));
    }

    SpringObjectPtr SpringInt::bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() & other->toInt());
        }
        return SpringObject::bitwiseAnd(other, env);
    }

    SpringObjectPtr SpringInt::bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() | other->toInt());
        }
        return SpringObject::bitwiseOr(other, env);
    }

    SpringObjectPtr SpringInt::bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() ^ other->toInt());
        }
        return SpringObject::bitwiseXor(other, env);
    }

    SpringObjectPtr SpringInt::bitwiseComplement(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(~(this->toInt()));
    }

    SpringObjectPtr SpringInt::bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() << other->toInt());
        }
        return SpringObject::bitwiseShiftLeft(other, env);
    }

    SpringObjectPtr SpringInt::bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            return env.ojbManager->create(this->toInt() >> other->toInt());
        }
        return SpringObject::bitwiseShiftRight(other, env);
    }

    std::string SpringInt::getPrintString()
    {
        return std::to_string(value);
    }

    bool SpringInt::toBool()
    {
        return value != 0;
    }

    int SpringInt::toInt()
    {
        return value;
    }

    double SpringInt::toDouble()
    {
        return (double)value;
    }

    std::string SpringInt::toString()
    {
        return std::to_string(value);
    }

    /***********************************************************************
    SpringDouble
    ***********************************************************************/

    SpringDouble::SpringDouble() :
        value(0.0)
    {
        type = SPR_DOULBE;
    }

    SpringDouble::SpringDouble(double d) :
        value(d)
    {
        type = SPR_DOULBE;
    }

    SpringObjectPtr SpringDouble::add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt() || other->isDouble())
            return env.ojbManager->create(this->toDouble() + other->toDouble());
        return SpringObject::add(other, env);
    }

    SpringObjectPtr SpringDouble::subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt() || other->isDouble())
            return env.ojbManager->create(this->toDouble() - other->toDouble());
        return SpringObject::subtract(other, env);
    }

    SpringObjectPtr SpringDouble::opposite(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(-(this->toDouble()));
    }

    SpringObjectPtr SpringDouble::multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt() || other->isDouble())
            return env.ojbManager->create(this->toDouble() * other->toDouble());
        return SpringObject::multiply(other, env);
    }

    SpringObjectPtr SpringDouble::power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt() || other->isDouble())
            return env.ojbManager->create(pow(this->toDouble(), other->toDouble()));
        return SpringObject::power(other, env);
    }

    SpringObjectPtr SpringDouble::divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt() || other->isDouble())
            return env.ojbManager->create(this->toDouble() / other->toDouble());
        return SpringObject::divide(other, env);
    }

    SpringObjectPtr SpringDouble::increment(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(this->toDouble() + 1);
    }

    SpringObjectPtr SpringDouble::decrement(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(this->toDouble() - 1);
    }

    SpringObjectPtr SpringDouble::greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() > other->toDouble());
        default:
            break;
        }
        return SpringObject::greater(other, env);
    }

    SpringObjectPtr SpringDouble::greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() >= other->toDouble());
        default:
            break;
        }
        return SpringObject::greaterEqual(other, env);
    }

    SpringObjectPtr SpringDouble::less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() < other->toDouble());
        default:
            break;
        }
        return SpringObject::less(other, env);
    }

    SpringObjectPtr SpringDouble::lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() <= other->toDouble());
        default:
            break;
        }
        return SpringObject::lessEqual(other, env);
    }

    SpringObjectPtr SpringDouble::equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() == other->toDouble());
        default:
            break;
        }
        return SpringObject::equal(other, env);
    }

    SpringObjectPtr SpringDouble::notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toDouble() != other->toDouble());
        default:
            break;
        }
        return SpringObject::notEqual(other, env);
    }

    SpringObjectPtr SpringDouble::logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toBool() && other->toBool());
        default:
            break;
        }
        return SpringObject::logicalAnd(other, env);
    }

    SpringObjectPtr SpringDouble::logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        case SPR_DOULBE:
            return env.ojbManager->create(this->toBool() || other->toBool());
        default:
            break;
        }
        return SpringObject::logicalOr(other, env);
    }

    SpringObjectPtr SpringDouble::logicalNot(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(!(this->toBool()));
    }

    std::string SpringDouble::getPrintString()
    {
        return std::to_string(value);
    }

    bool SpringDouble::toBool()
    {
        return value != 0.0;
    }

    int SpringDouble::toInt()
    {
        return (int)value;
    }

    double SpringDouble::toDouble()
    {
        return value;
    }

    std::string SpringDouble::toString()
    {
        return std::to_string(value);
    }

    /***********************************************************************
    SpringString
    ***********************************************************************/

    SpringString::SpringString():
        value("")
    {
        type = SPR_STRING;
    }

    SpringString::SpringString(const std::string &s):
        value(s)
    {
        type = SPR_STRING;
    }

    SpringObjectPtr SpringString::add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isString())
            return env.ojbManager->create(this->toString() + other->toString());
        return SpringObject::add(other, env);
    }

    SpringObjectPtr SpringString::subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            std::string str = this->toString();
            int strLen = str.length();
            if(strLen == 0)
                return env.ojbManager->create();

            int index = other->toInt();
            int realIndex = index % strLen;
            if(realIndex < 0)
                realIndex += strLen;
            str.erase(realIndex, 1);
            return env.ojbManager->create(str);
        }
        return SpringObject::subtract(other, env);
    }

    SpringObjectPtr SpringString::opposite(SpringRuntimeEnvironment &env)
    {
        std::string str = this->toString();
        return env.ojbManager->create(std::string(str.rbegin(), str.rend()));
    }

    SpringObjectPtr SpringString::multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            int n = other->toInt();
            if(n < 0)
                SpringException::throwRawException("When a string is multiplied by an integer, the integer must be positive or 0.");

            std::string str = this->toString();
            std::string resultStr = "";
            for (int i = 0; i < n; i++)
                resultStr.append(str);
            return env.ojbManager->create(resultStr);
        }
        return SpringObject::multiply(other, env);
    }

    SpringObjectPtr SpringString::equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isString()){
            return env.ojbManager->create(value == other->toString());
        }
        return SpringObject::equal(other, env);
    }

    SpringObjectPtr SpringString::notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isString()){
            return env.ojbManager->create(value != other->toString());
        }
        return SpringObject::notEqual(other, env);
    }

    SpringObjectPtr SpringString::getItem(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        {
            std::string str = this->toString();
            int strLen = str.length();
            if(strLen == 0)
                return env.ojbManager->create();

            int index = other->toInt();
            int realIndex = index % strLen;
            if(realIndex < 0)
                realIndex += strLen;
            return env.ojbManager->create(std::to_string(str[realIndex]));
        }
        case SPR_LIST:
        {
            std::string str = this->toString();
            int strLen = str.length();
            if(strLen == 0)
                return env.ojbManager->create();

            std::string newStr = "";
            std::vector<SpringObjectPtr> indexList = other->toListPointer()->getAll();
            for(auto i : indexList){
                int index = i->toInt();
                int realIndex = index % strLen;
                if(realIndex < 0)
                    realIndex += strLen;
                newStr.append(std::to_string(str[realIndex]));
            }
            return env.ojbManager->create(newStr);
        }
        default:
            break;
        }
        return SpringObject::getItem(other, env);
    }

    void SpringString::setItem(const SpringObjectPtr &index, const SpringObjectPtr &value, SpringRuntimeEnvironment &env)
    {
        if(!index->isInt())
            SpringObject::setItem(index, value, env);

        SpringException::throwRawException("TODO: string[int]");
    }

    void SpringString::delItem(const SpringObjectPtr &index, SpringRuntimeEnvironment &env)
    {
        if(!index->isInt())
            SpringObject::delItem(index, env);

        // TODO:del string[int]
        SpringException::throwRawException("TODO: del string[int]");
    }

    SpringObjectPtr SpringString::size(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(value.length());
    }

    std::string SpringString::getPrintString()
    {
        return value;
    }

    bool SpringString::toBool()
    {
        return !value.empty();
    }

    int SpringString::toInt()
    {
        try{
            return std::stoi(value);
        }catch(std::exception &){
            SpringException::throwRuntimeError("TypeError: unable to convert string \"" + value + "\" to int");
        }
        return 0;
    }

    double SpringString::toDouble()
    {
        try{
            return std::stod(value);
        }catch(std::exception &){
            SpringException::throwRuntimeError("TypeError: unable to convert string \"" + value + "\" to int");
        }
        return 0.0;
    }

    std::string SpringString::toString()
    {
        return value;
    }

    /***********************************************************************
    SpringMatrix
    ***********************************************************************/

    SpringMatrix::SpringMatrix()
    {
        type = SPR_MATRIX;
    }

    SpringObjectPtr SpringMatrix::size(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(0);
    }

    std::string SpringMatrix::getPrintString()
    {
        return "TODO: matrix";
    }

    /***********************************************************************
    SpringList
    ***********************************************************************/

    SpringList::SpringList()
    {
        type = SPR_LIST;
    }

    SpringList::SpringList(const std::vector<SpringObjectPtr> &l)
    {
        type = SPR_LIST;
        value = l;
    }

    SpringObjectPtr SpringList::operator[](int i)
    {
        return value[i];
    }

    SpringObjectPtr SpringList::at(int i)
    {
        return value[i];
    }

    std::vector<SpringObjectPtr> SpringList::getAll()
    {
        return value;
    }

    unsigned SpringList::getLength()
    {
        return value.size();
    }

    void SpringList::set(int i, SpringObjectPtr p)
    {
        int listLength = getLength();
        if(listLength == 0){
            append(p);
            return;
        }
        int realIndex = i % listLength;
        if(realIndex < 0)
            realIndex += listLength;
        value[realIndex] = p;
    }

    void SpringList::append(SpringObjectPtr objPtr)
    {
        value.push_back(objPtr);
    }

    void SpringList::insert(int i, SpringObjectPtr p)
    {
        int listLength = getLength();
        if(listLength == 0)
        {
            append(p);
            return;
        }
        i = i % listLength;
        if(i < 0)
            i += listLength;
        auto iter = value.begin();
        while (i-- > 0)
            iter++;
        value.insert(iter, p);
    }

    void SpringList::remove(int i)
    {
        if(value.size() == 0)
            return;
        i = i % value.size();
        if(i < 0)
            i += value.size();
        auto iter = value.begin();
        while (i-- > 0)
            iter++;
        value.erase(iter);
    }

    void SpringList::clear()
    {
        value.clear();
    }

    SpringObjectPtr SpringList::add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isList()){
            auto list0 = getAll();
            auto list1 = other->toListPointer()->getAll();
            std::vector<SpringObjectPtr> list;
            for(auto i : list0)
                list.push_back(i);
            for(auto i : list1)
                list.push_back(i);
            return env.ojbManager->create(list);
        }
        return SpringObject::add(other, env);
    }

    SpringObjectPtr SpringList::subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            std::vector<SpringObjectPtr> ptrList = getAll();
            int listSize = ptrList.size();
            if(listSize == 0)
                return env.ojbManager->create();

            int index = other->toInt();
            int realIndex = index % listSize;
            if(realIndex < 0)
                realIndex += listSize;
            auto iter = ptrList.begin();
            while (realIndex-- > 0) {
                iter++;
            }
            ptrList.erase(iter);
            return env.ojbManager->create(ptrList);
        }
        return SpringObject::subtract(other, env);
    }

    SpringObjectPtr SpringList::opposite(SpringRuntimeEnvironment &env)
    {
        std::vector<SpringObjectPtr> list = getAll();
        std::reverse(list.begin(), list.end());
        return env.ojbManager->create(list);
    }

    SpringObjectPtr SpringList::multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isBool() || other->isInt()){
            int n = other->toInt();
            if(n < 0)
                SpringException::throwRawException("When a list is multiplied by an integer, the integer must be positive or 0.");

            auto sourseList = getAll();
            std::vector<SpringObjectPtr> resultList;
            for (int i = 0; i < n; i++)
                for(auto item : sourseList)
                    resultList.push_back(item);
            return env.ojbManager->create(resultList);
        }
        return SpringObject::multiply(other, env);
    }

    SpringObjectPtr SpringList::equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isList()){
            unsigned listLength = getLength();
            if(listLength != other->toListPointer()->getLength())
                return env.ojbManager->create(false);
            for(unsigned i = 0; i < listLength; i++){
                if(this->at(i) != other->toListPointer()->at(i))
                    return env.ojbManager->create(false);
            }
            return env.ojbManager->create(true);
        }
        return SpringObject::equal(other, env);
    }

    SpringObjectPtr SpringList::notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(other->isList()){
            unsigned listLength = getLength();
            if(listLength != other->toListPointer()->getLength())
                return env.ojbManager->create(true);

            for(unsigned i = 0; i < listLength; i++){
                if(this->at(i) != other->toListPointer()->at(i))
                    return env.ojbManager->create(true);
            }
            return env.ojbManager->create(false);
        }
        return SpringObject::notEqual(other, env);
    }

    SpringObjectPtr SpringList::getItem(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        switch (other->getType()) {
        case SPR_BOOL:
        case SPR_INT:
        {
            std::vector<SpringObjectPtr> ptrList = getAll();
            int listSize = ptrList.size();
            if(listSize == 0)
                return env.ojbManager->create();

            int index = other->toInt();
            int realIndex = index % listSize;
            if(realIndex < 0)
                realIndex += listSize;
            return ptrList[realIndex];
        }
        case SPR_LIST:
        {
            std::vector<SpringObjectPtr> ptrList = getAll();
            int listSize = ptrList.size();
            if(listSize == 0)
                return env.ojbManager->create();

            std::vector<SpringObjectPtr> newList;
            std::vector<SpringObjectPtr> indexList = other->toListPointer()->getAll();
            for(auto i : indexList){
                int index = i->toInt();
                int realIndex = index % listSize;
                if(realIndex < 0)
                    realIndex += listSize;
                newList.push_back(ptrList[realIndex]);
            }
            return env.ojbManager->create(newList);
        }
        default:
            break;
        }
        return SpringObject::getItem(other, env);
    }

    void SpringList::setItem(const SpringObjectPtr &index, const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        if(!index->isInt())
            SpringObject::setItem(index, other, env);
        set(index->toInt(), other);
    }

    void SpringList::delItem(const SpringObjectPtr &index, SpringRuntimeEnvironment &env)
    {
        if(!index->isInt())
            SpringObject::delItem(index, env);

        remove(index->toInt());
    }

    SpringObjectPtr SpringList::newInstance(SpringRuntimeEnvironment &env)
    {
        std::vector<SpringObjectPtr> newList;
        for(SpringObjectPtr i : value){
            if(i->isStruct() || i->isList())
                newList.push_back(i->newInstance(env));
            else
                newList.push_back(i);
        }
        return env.ojbManager->create(newList);
    }

    SpringObjectPtr SpringList::size(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create(value.size());
    }

    std::string SpringList::getPrintString()
    {
        std::string str = "[";
        for(unsigned i = 0; i < value.size(); i++){
            str += value[i]->getPrintString();
            if(i != value.size() - 1)
                str += ",";
        }
        str += "]";
        return str;
    }

    void SpringList::getPtr(std::vector<SpringObjectPtr> &ptrList)
    {
        for(auto item : value)
            item->getPtr(ptrList);
        ptrList.push_back(this);
    }

    void SpringList::getRelatedPtr(std::set<SpringObjectPtr> &ptrList)
    {
//        if(ptrList.count(this) != 0)
//            return;
        ptrList.insert(this);
        for(auto item : value)
            item->getRelatedPtr(ptrList);
    }

    SpringListPtr SpringList::toListPointer()
    {
        return this;
    }

    /***********************************************************************
    SpringFunction
    ***********************************************************************/

    SpringFunction::SpringFunction(SpringIDListExpression *i, SpringParagraph *b):
        inputParam(i),
        body(b)
    {
        type = SPR_FUNCTION;
    }

    SpringFunction::SpringFunction(const SpringStandardFunctionType &f, const std::string &d):
        isStandardFunction(true),
        stdFunction(f),
        funcDescription(d)
    {
        type = SPR_FUNCTION;
    }

    SpringObjectPtr SpringFunction::call(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
        if(isStandardFunction)
            return stdFunction(args, env);

        // check the arguments
        int minArgNum = 0, maxArgNum = 0;
        if(inputParam != nullptr){
            minArgNum = inputParam->getNondefaultArgumentNum();
            maxArgNum = inputParam->size();
        }
        int acturalArgNum = args.size();
        if(acturalArgNum < minArgNum)
            SpringException::throwRuntimeError("Too few arguments.");
        if(acturalArgNum > maxArgNum)
            SpringException::throwRuntimeError("Too many arguments.");

        env.symbolTable->entryScope();
        if(self != nullptr)
            env.symbolTable->declare("this", self);
        else
            env.symbolTable->declare("this", env.ojbManager->create());

        for(int i = 0; i < maxArgNum; i++){
            if(i < acturalArgNum){
                env.symbolTable->declare(inputParam->at(i)->getName(), args[i]);
            }else{
                auto id = inputParam->at(i);
                env.symbolTable->declare(id->getName(), id->getDefaultValue(env));
            }
        }

        if(body != nullptr){
//            env.symbolTable->print();
            SpringBaseStatement::SpringStatementResultFlag r = body->run(env);
//            std::cout << "\n***************************q\n";
            if(r == SpringBaseStatement::SpringStatementResultFlag::RETURN){
                SpringObjectPtr r = env.ojbManager->popReturnValue();
                env.symbolTable->exitScope();
                return r;
            }
        }
        env.symbolTable->exitScope();
        return env.ojbManager->create();
    }

    void SpringFunction::getPtr(std::vector<SpringObjectPtr> &ptrList)
    {
        if(self != nullptr)
            self->getPtr(ptrList);
        ptrList.push_back(this);
    }

    void SpringFunction::getRelatedPtr(std::set<SpringObjectPtr> &ptrList)
    {
//        if(ptrList.count(this) != 0)
//            return;
        ptrList.insert(this);
        if(self != nullptr)
            self->getRelatedPtr(ptrList);
    }

    SpringFunctionPtr SpringFunction::toFunctionPointer()
    {
        return this;
    }

    std::string SpringFunction::getPrintString()
    {
        if(isStandardFunction)
            return "Spring standard function";
        int argNum = 0;
        if(inputParam != nullptr)
            argNum = inputParam->size();
        return "User-defined function with " + std::to_string(argNum) + " positional arguments";
    }

    void SpringFunction::setSelf(const SpringObjectPtr &s)
    {
        self = s;
    }

    /***********************************************************************
    SpringStruct
    ***********************************************************************/

    SpringStruct::SpringStruct()
    {
        type = SPR_STRUCT;
    }

    SpringStruct::SpringStruct(const std::map<std::string, SpringObjectPtr> &s)
    {
        type = SPR_STRUCT;
        this->members = std::move(s);
    }

    SpringObjectPtr SpringStruct::getMember(const std::string &key)
    {
        SpringObjectPtr m;
        auto it = members.find(key);
        if(it == members.end()){
            auto it2 = members.find(PROTOTYPE_KEY);
            if(it2 == members.end())
                SpringException::throwRuntimeError("There is no member named " + key + " in the object");

            SpringObjectPtr proto = it2->second;
            if(!proto->isStruct())
                SpringException::throwRuntimeError("There is no member named " + key + " in the object");

            m = proto->toStructPointer()->getMember(key);
        }else {
            m = it->second;
        }

        if(m->isFunction())
            m->toFunctionPointer()->setSelf(this);
        return m;
    }

    bool SpringStruct::existMember(const std::string &key)
    {
        auto it = members.find(key);
        if(it == members.end()){
            auto it2 = members.find(PROTOTYPE_KEY);
            if(it2 == members.end())
                return false;
            SpringObjectPtr proto = it2->second;
            if(!proto->isStruct())
                return false;
            return proto->toStructPointer()->existMember(key);
        }
        return true;
    }

    void SpringStruct::addMember(const std::string &key, SpringObjectPtr p)
    {
        auto it = members.find(key);
        if(it != members.end())
            members.erase(it);

        if(key.compare(PROTOTYPE_KEY) == 0 && !(p->isStruct()))
            SpringException::throwRawException("The prototype must be a struct.");
        members.insert(std::make_pair(key, p));
    }

    void SpringStruct::getPtr(std::vector<SpringObjectPtr> &ptrList)
    {
        for(auto iter : members){
            if(iter.second->isFunction())
                ptrList.push_back(iter.second);
            else
                iter.second->getPtr(ptrList);
        }
        ptrList.push_back(this);
    }

    void SpringStruct::getRelatedPtr(std::set<SpringObjectPtr> &ptrList)
    {
//        if(ptrList.count(this) != 0)
//            return;
        ptrList.insert(this);
        for(auto iter : members){
            if(iter.second->isFunction())
                ptrList.insert(iter.second);
            else
                iter.second->getRelatedPtr(ptrList);
        }
    }

    SpringStructPtr SpringStruct::toStructPointer()
    {
        return this;
    }

    SpringObjectPtr SpringStruct::add(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("+")
    }

    SpringObjectPtr SpringStruct::subtract(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("-")
    }

    SpringObjectPtr SpringStruct::multiply(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("*")
    }

    SpringObjectPtr SpringStruct::power(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("**")
    }

    SpringObjectPtr SpringStruct::divide(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("/")
    }

    SpringObjectPtr SpringStruct::mod(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("%")
    }

    SpringObjectPtr SpringStruct::opposite(SpringRuntimeEnvironment &env)
    {
        unaryOperator("---")
    }

    SpringObjectPtr SpringStruct::increment(SpringRuntimeEnvironment &env)
    {
        unaryOperator("++")
    }

    SpringObjectPtr SpringStruct::decrement(SpringRuntimeEnvironment &env)
    {
        unaryOperator("--")
    }

    SpringObjectPtr SpringStruct::greater(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator(">")
    }

    SpringObjectPtr SpringStruct::greaterEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator(">=")
    }

    SpringObjectPtr SpringStruct::less(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("<")
    }

    SpringObjectPtr SpringStruct::lessEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("<=")
    }

    SpringObjectPtr SpringStruct::equal(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("==")
    }

    SpringObjectPtr SpringStruct::notEqual(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("!=")
    }

    SpringObjectPtr SpringStruct::logicalAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("&&")
    }

    SpringObjectPtr SpringStruct::logicalOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("||")
    }

    SpringObjectPtr SpringStruct::logicalNot(SpringRuntimeEnvironment &env)
    {
        unaryOperator("!")
    }

    SpringObjectPtr SpringStruct::bitwiseAnd(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("&")
    }

    SpringObjectPtr SpringStruct::bitwiseOr(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("|")
    }

    SpringObjectPtr SpringStruct::bitwiseXor(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("^")
    }

    SpringObjectPtr SpringStruct::bitwiseComplement(SpringRuntimeEnvironment &env)
    {
        unaryOperator("~")
    }

    SpringObjectPtr SpringStruct::bitwiseShiftLeft(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("<<")
    }

    SpringObjectPtr SpringStruct::bitwiseShiftRight(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator(">>")
    }

    SpringObjectPtr SpringStruct::getItem(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        binaryOperator("[]")
    }

    SpringObjectPtr SpringStruct::size(SpringRuntimeEnvironment &env)
    {
        if(existMember("#")){
            unaryOperator("#")
        }
        return env.ojbManager->create(members.size());
    }

    SpringObjectPtr SpringStruct::newInstance(SpringRuntimeEnvironment &env)
    {
        std::map<std::string, SpringObjectPtr> newMembers;
        for(auto iter : members){
            if(iter.second->isStruct() || iter.second->isList())
                newMembers.insert(std::make_pair(iter.first, iter.second->newInstance(env)));
            else
                newMembers.insert(std::make_pair(iter.first, iter.second));
        }
        return env.ojbManager->create(newMembers);
    }

    SpringObjectPtr SpringStruct::call(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
        SpringObjectPtr operatorFunc = getMember("()");
        if(!operatorFunc->isFunction())
            SpringException::throwUnknownOperatorException("()", {getType()});
        return operatorFunc->call(args, env);
    }

    SpringObjectPtr SpringStruct::getAttribute(const std::string &key, SpringRuntimeEnvironment &env)
    {
        std::string op = ".";
        if(existMember(op)){
            SpringObjectPtr other = env.ojbManager->create(key);
            SpringObjectPtr operatorFunc = getMember(op);
            if(!operatorFunc->isFunction())
                SpringException::throwUnknownOperatorException(op, {getType(), other->getType()});
            return operatorFunc->call({other}, env);
        }
        return getMember(key);
    }

    void SpringStruct::setAttribute(const std::string &key, const SpringObjectPtr &other, SpringRuntimeEnvironment &)
    {
        auto it = members.find(key);
        if(it != members.end())
            members.erase(it);

        if(key.compare(PROTOTYPE_KEY) == 0 && !(other->isStruct()))
            SpringException::throwRawException("The prototype must be a struct.");
        members.insert(std::make_pair(key, other));
    }

    void SpringStruct::setPrototype(const SpringObjectPtr &other, SpringRuntimeEnvironment &env)
    {
        std::string key = PROTOTYPE_KEY;
        setAttribute(key, other, env);
    }

    std::string SpringStruct::getPrintString()
    {
        std::string str = "{";
        for(auto i : members)
        {
            str += i.first;
            str += ": ";
            str += i.second->getPrintString();
            str += ",";
        }
        str = str.substr(0, str.length() - 1);
        str += "}";
        return str;
    }

    /***********************************************************************
    SpringVoidPointer
    ***********************************************************************/

    SpringAny::SpringAny(void *p, const std::string &c):
        ptr(p),
        className(c)
    {
        type = SPR_POINTER;
    }

    void *SpringAny::toPointer(const std::string &c)
    {
        if(className == c)
            return ptr;
        SpringException::throwRuntimeError("TypeError: unable to convert pointer(" + className + ") to pointer(" + c + ")");
        return nullptr;
    }

    std::string SpringAny::getPrintString()
    {
        return "pointer(" + className + ")";
    }

}
