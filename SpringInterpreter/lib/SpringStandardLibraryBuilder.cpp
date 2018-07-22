//#include "SpringStandardLibraryBuilder.h"

//#include <time.h>
//#include <armadillo>

//#include "Spring.h"
//#include "SpringStandardFunction.h"

//namespace spr {

//    SpringStandardLibraryBuilder::SpringStandardLibraryBuilder()
//    {}

//    SpringStandardLibrary SpringStandardLibraryBuilder::build()
//    {
//        SpringStandardLibrary lib(getLibraryName(),
//                                  getLibraryDescription(),
//                                  getLibraryAuthor(),
//                                  getLibraryVersion());
//        std::vector<SpringStandardLibrary::SpringStandardLibraryFunction> funcList = getFuncList();
//        for(auto func : funcList)
//            lib.registerFunction(func);
//        return lib;
//    }

//    std::string SpringStandardLibraryBuilder::getLibraryName()
//    {
//        return "Spring";
//    }

//    std::string SpringStandardLibraryBuilder::getLibraryDescription()
//    {
//        return "Spring Standard Library";
//    }

//    std::string SpringStandardLibraryBuilder::getLibraryAuthor()
//    {
//        return "Rocket";
//    }

//    std::string SpringStandardLibraryBuilder::getLibraryVersion()
//    {
//        return "v0.1";
//    }

//    std::vector<SpringStandardLibrary::SpringStandardLibraryFunction> SpringStandardLibraryBuilder::getFuncList()
//    {
//    //    SpringStandardLibraryFunctionType print = [](const std::deque<Container> &paramList,
//    //            SpringRuntimeEnvironment &runtimeEnvironment) -> Container
//    //    {
//    //        if(paramList.size() == 0){
//    //            // print the entire Symbol table
//    //            auto symbols = runtimeEnvironment.symbolTable.getAll();
//    //            std::string output = "";
//    //            for (auto sym : symbols)
//    //            {
//    //                output += sym.first;
//    //                output += "		";
//    //                output += sym.second.getStrType();
//    //                output += "		";
//    //                output += sym.second.toString();
//    //                output += "\n";
//    //            }
//    //            runtimeEnvironment.springIOHelper->print(output);
//    //        }else{
//    //            std::string output = "";
//    //            for(auto c : paramList)
//    //                output += c.toString() + ' ';
//    //            runtimeEnvironment.springIOHelper->print(output);
//    //        }
//    //        return 0.0;
//    //    };

//    //    SpringStandardLibraryFunctionType type = [](const std::deque<Container> &paramList,
//    //            SpringRuntimeEnvironment &runtimeEnvironment) -> Container
//    //    {
//    //        // chech parameters
//    //        for(auto i : paramList)
//    //        {
//    //            if(!i.isString()){
//    //                Spring::throwRawException("type函数的参数必须为字符串类型");
//    //            }
//    //        }

//    //        std::deque<Container> typeList;
//    //        for(auto i : paramList)
//    //        {
//    //            std::string type = runtimeEnvironment.symbolTable[i.str].getStrType();
//    //            std::string printStr = i.str + ": " + type;
//    //            runtimeEnvironment.springIOHelper->print(printStr);
//    //            typeList.push_back(Container(type));
//    //        }
//    //        if(typeList.size() == 1)
//    //            return Container(typeList[0]);
//    //        else
//    //            return Container(typeList);
//    //    };

//    ////    SpringStandardLibFunctionType sendEmail = [](const std::deque<Container> &paramList, SymbolTable &table,
//    ////            SpringIOHelper &ioHelper) -> Container
//    ////    {
//    ////        // check parameters
//    ////        if(paramList.size() != 5)
//    ////            Spring::throwRawException("sendEmail函数的包含5个参数：发送者邮箱，发送者邮箱密码，接收者邮箱，邮件主题，邮件内容");
//    ////        for(auto i : paramList)
//    ////            if(!i.isString())
//    ////                Spring::throwRawException("sendEmail函数的参数必须为字符串类型");

//    ////        QString senderAddr = QString::fromStdString(paramList[0].str);
//    ////        QString senderPassword = QString::fromStdString(paramList[1].str);
//    ////        QString receiverAddr = QString::fromStdString(paramList[2].str);
//    ////        QString theme = QString::fromStdString(paramList[3].str);
//    ////        QString content = QString::fromStdString(paramList[4].str);

//    ////        // 这里用来测试 发送邮件
//    ////        EmailHelper h;
//    ////        EmailHelper::SendEmailResult r =
//    ////                h.sendEmail_QQ(senderAddr, senderPassword, receiverAddr, theme, content);

//    ////        if(!r.success){
//    ////            std::string result = r.errorTip.toStdString();
//    ////            Spring::throwRawException(result);
//    ////        }

//    ////        return true;
//    ////    };


//    //    SpringStandardLibraryFunctionType systemFunc = [](const std::deque<Container> &paramList,
//    //            SpringRuntimeEnvironment &runtimeEnvironment) -> Container
//    //    {
//    //        // check parameters
//    //        if(paramList.size() != 1)
//    //            Spring::throwRawException("system函数包含1个字符串类型参数，即命令字符串");
//    //        Container c = paramList[0];
//    //        if(!c.isString())
//    //            Spring::throwRawException("system函数的参数必须为字符串类型");

//    //        int code = system(paramList[0].str.data());
//    //        return Container(code);
//    //    };


//    //    SpringStandardLibraryFunctionType plot = [](const std::deque<Container> &paramList,
//    //            SpringRuntimeEnvironment &runtimeEnvironment) -> Container
//    //    {
//    //        // check parameters
//    //        if(paramList.size() == 0)
//    //            Spring::throwRawException("plot函数的参数不可为空");

//    //        for(auto item : paramList)
//    //        {
//    //            if(!item.isList())
//    //                Spring::throwRawException("plot函数的所有参数必须为list类型，且list中各元素必须为number类型");
//    //            else
//    //                for(auto i : item.list)
//    //                    if(!i.isNumber())
//    //                        Spring::throwRawException("plot函数的所有参数必须为list类型，且list中各元素必须为number类型");
//    //        }

//    //        Container c(paramList);
//    //        runtimeEnvironment.springIOHelper->onShowChart(c);
//    //        return true;
//    //    };

//    ////    SpringStandardLibraryFunctionType rand = [](const std::deque<Container> &paramList,
//    ////            SymbolTable &table,
//    ////            SpringIOHelper &ioHelper,
//    ////            SpringRuntimeLibrary &runtimeLibrary) -> Container
//    ////    {
//    ////        // check parameters
//    ////        if(paramList.size() != 0)
//    ////            Spring::throwRawException("rand函数不接受任何参数");

//    ////        return Container(qrand()/(double(RAND_MAX)));
//    ////    };



//        return {

//    // **BASIC*******************************************************
//            {"print", "打印一个或多个变量的值；当以0参数调用时，打印当前全部变量的值", print},
////            {"del", "删除某一个或多个变量", del},
////            {"type", "显示一个或多个变量的数据类型", type},
////            {"sendEmail", "发送邮件", sendEmail},
////            {"input", "获取标准输入，返回一个字符串类型的数据", inputFunc},


////            {"plot", "绘制二维曲线图", plot},
////            {"rand", "获取0-1之间的随机数", rand},
////            {"clear", "清空输出窗口", clearFunc},
////            {"clearall", "清空全部，包括输出窗口和工作区", clearallFunc},
////            {"import", "加载Spring标准库或第三方库", importFunc},
////            {"info", "显示Spring库（Spring标准库或扩展库）的信息", infoFunc},
////            {"help", "显示关于某字符串的帮助信息", helpFunc},

//    // **MATH*******************************************************
////            {"math_randu", "按均匀分布生成一个随机矩阵", randuFunc},
////            {"math_randn", "按正态分布生成一个随机矩阵", randnFunc},
////            {"math_ones", "生成元素均为0的矩阵", onesFunc},
////            {"math_zeros", "生成元素均为1矩阵", zerosFunc},
////            {"math_eye", "生成一个主对角线为1，其余元素为0的矩阵", eyeFunc},
////            {"math_inv", "求一个方阵的逆矩阵", invFunc},
////            {"math_pinv", "求一个矩阵的伪逆矩阵", pinvFunc},
////            {"math_sin", "", notDefinedFunc},
////            {"math_cos", "", notDefinedFunc},
////            {"math_tan", "", notDefinedFunc},
////            {"math_asin", "", notDefinedFunc},
////            {"math_acos", "", notDefinedFunc},
////            {"math_atan", "", notDefinedFunc},
////            {"math_sinh", "", notDefinedFunc},
////            {"math_cosh", "", notDefinedFunc},
////            {"math_tanh", "", notDefinedFunc},
////            {"math_ceil", "", notDefinedFunc},
////            {"math_floor", "", notDefinedFunc},
////            {"math_deg", "", notDefinedFunc},
////            {"math_rad", "", notDefinedFunc},
////            {"math_abs", "", notDefinedFunc},
////            {"math_sqrt", "", notDefinedFunc},
////            {"math_exp", "", notDefinedFunc},
////            {"math_log", "", notDefinedFunc},
////            {"math_mod", "", notDefinedFunc},
////            {"math_max", "", notDefinedFunc},
////            {"math_min", "", notDefinedFunc},
////            {"math_random", "", notDefinedFunc},
////            {"math_randomseed", "", notDefinedFunc},
////            {"math_PI", "", notDefinedFunc},
////            {"math_HUGE", "", notDefinedFunc},

//    // **LIST*******************************************************
////            {"list_len", "求一个list的长度", lengthFunc},
////            {"list_insert", "", notDefinedFunc},
////            {"list_remove", "删除一个list中指定位置的元素", listRemoveFunc},
////            {"list_append", "", notDefinedFunc},
////            {"list_sort", "", notDefinedFunc},

//    // **STRING*******************************************************
////            {"string_len", "", notDefinedFunc},
////            {"string_lower", "", notDefinedFunc},
////            {"string_upper", "", notDefinedFunc},
////            {"string_reverse", "", notDefinedFunc},
////            {"string_sub", "", notDefinedFunc},
////            {"string_find", "", notDefinedFunc},
////            {"string_format", "", notDefinedFunc},

//    // **IO/FILE*******************************************************
////            {"file_open", "", notDefinedFunc},
////            {"file_remove", "", notDefinedFunc},
////            {"file_rename", "", notDefinedFunc},
////            {"file_write", "", notDefinedFunc},
////            {"file_read", "", notDefinedFunc},
////            {"file_lines", "", notDefinedFunc},
////            {"file_close", "", notDefinedFunc},

//    // **OS*******************************************************
//            {"os_clock", "返回CPU时钟", os_clock}
////            {"os_date", "", notDefinedFunc},
////            {"os_time", "", notDefinedFunc},
////            {"os_getenv", "", notDefinedFunc},
////            {"os_system", "调用系统命令", systemFunc}

//        };
//    }

//    //Container importFunc(const std::deque<Container> &args,
//    //                       SpringRuntimeEnvironment &runtimeEnvironment)
//    //{
//    //    // check parameters
//    //    if(args.size() != 1)
//    //        Spring::throwRawException("import函数只能包含一个参数，即dll文件的路径");

//    //    Container argument = args[0];
//    //    if(!(argument.isString()))
//    //        Spring::throwRawException("import函数只能包含一个参数，且必须为字符串类型的dll文件的路径");

//    //    std::string thirdPartyLibPath = argument.str;
//    //    runtimeEnvironment.springRuntimeLib.addExtensionLibrary(thirdPartyLibPath);
//    //    return true;
//    //}

//    //Container infoFunc(const std::deque<Container> &args,
//    //                     SpringRuntimeEnvironment &env)
//    //{
//    //    // check parameters
//    //    if(args.size() > 1)
//    //        Spring::throwRawException("info函数只能接受0个或1个字符串类型参数");

//    //    if(args.size() == 0){
//    //        std::deque<std::string> libs = env.springRuntimeLib.getAllLibraries();

//    //        qDebug()<< "infoFunc";
//    //        for(auto l : libs){
//    //            qDebug()<<QString::fromStdString(l);
//    //        }

//    //        env.springIOHelper->onShowLibInfo(libs);
//    //        return true;
//    //    }

//    //    Container argument = args[0];
//    //    if(!(argument.isString()))
//    //        Spring::throwRawException("info函数只能包含一个字符串类型参数，即Spring库的名字");

//    //    std::string libName = argument.str;
//    //    if(!env.springRuntimeLib.existLibrary(libName))
//    //        Spring::throwRawException("Unknown Spring library: " + libName);

//    //    env.springIOHelper->onShowLibInfo({libName});
//    //    return true;
//    //}

//    //void clearFunc(SpringRuntimeEnvironment &runtimeEnvironment)
//    //{
//    //    runtimeEnvironment.springIOHelper->clearOutput();
//    //}

//    //void clearallFunc(SpringRuntimeEnvironment &runtimeEnvironment)
//    //{
//    //    runtimeEnvironment.springIOHelper->clearOutput();
//    //    runtimeEnvironment.symbolTable.clear();
//    //    runtimeEnvironment.springRuntimeLib.clearupRuntimeLibraries();
//    //}

//    //Container randuFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() != 2)
//    //        Spring::throwRawException("randu函数必须包含2个整型输入参数");

//    //    Container arg1 = args[0];
//    //    Container arg2 = args[1];

//    //    if(!arg1.isNumber() || !arg2.isNumber())
//    //        Spring::throwRawException("randu函数的两个输入参数必须为整数类型");

//    //    arma::mat m = arma::randu<arma::mat>(arg1.toInt(), arg2.toInt());
//    //    return m;
//    //}
//    //Container randnFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() != 2)
//    //        Spring::throwRawException("randn函数必须包含2个整型输入参数");

//    //    Container arg1 = args[0];
//    //    Container arg2 = args[1];

//    //    if(!arg1.isNumber() || !arg2.isNumber())
//    //        Spring::throwRawException("randn函数的两个输入参数必须为整数类型");

//    //    arma::mat m = arma::randn(arg1.toInt(), arg2.toInt());
//    //    return m;
//    //}
//    //Container onesFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() != 2)
//    //        Spring::throwRawException("ones函数包含2个整型参数");

//    //    Container arg1 = args[0];
//    //    Container arg2 = args[1];

//    //    if(!arg1.isNumber() || !arg2.isNumber())
//    //        Spring::throwRawException("ones函数的两个输入参数必须为整数类型");

//    //    arma::mat m = arma::ones<arma::mat>(arg1.toInt(), arg2.toInt());
//    //    return m;
//    //}
//    //Container zerosFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() != 2)
//    //        Spring::throwRawException("zeros函数包含2个整型参数");

//    //    Container arg1 = args[0];
//    //    Container arg2 = args[1];

//    //    if(!arg1.isNumber() || !arg2.isNumber())
//    //        Spring::throwRawException("zeros函数的两个输入参数必须为整数类型");

//    //    arma::mat m = arma::zeros<arma::mat>(arg1.toInt(), arg2.toInt());
//    //    return m;
//    //}
//    //Container eyeFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() != 2)
//    //        Spring::throwRawException("eye函数必须包含2个整型输入参数");

//    //    Container arg1 = args[0];
//    //    Container arg2 = args[1];

//    //    if(!arg1.isNumber() || !arg2.isNumber())
//    //        Spring::throwRawException("eye函数的两个输入参数必须为整数类型");

//    //    arma::mat m = arma::eye<arma::mat>(arg1.toInt(), arg2.toInt());
//    //    return m;
//    //}
//    //Container invFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() <= 0)
//    //        Spring::throwRawException("inv函数至少包含一个参数");

//    //    for(auto arg : args){
//    //        if(!arg.isMatrix())
//    //            Spring::throwRawException("inv函数的参数必须为矩阵");
//    //    }

//    //    std::deque<Container> result;
//    //    for(auto arg : args){
//    //        result.push_back(arg.inv());
//    //    }
//    //    if(result.size() == 1)
//    //        return result[0];
//    //    return result;
//    //}
//    //Container pinvFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() <= 0)
//    //        Spring::throwRawException("pinv函数至少包含一个参数");

//    //    for(auto arg : args){
//    //        if(!arg.isMatrix())
//    //            Spring::throwRawException("pinv函数的参数必须为矩阵");
//    //    }

//    //    std::deque<Container> result;
//    //    for(auto arg : args){
//    //        result.push_back(arg.pinv());
//    //    }
//    //    if(result.size() == 1)
//    //        return result[0];
//    //    return result;
//    //}

//    //Container clockFunc()
//    //{
//    //    double c = (double)(clock())/(double)CLK_TCK;
//    //    return c;
//    //}

//    //Container helpFunc(const std::deque<Container> &args, SpringRuntimeEnvironment &env)
//    //{
//    //    if(args.size() == 0){
//    //        std::deque<std::string> libs = env.springRuntimeLib.getAllLibraries();
//    //        env.springIOHelper->onShowLibInfo(libs);
//    //        return true;
//    //    }

//    //    if(args.size() != 1)
//    //        Spring::throwRawException("help函数只能接受1个字符串类型参数");
//    //    Container argument = args[0];
//    //    if(!(argument.isString()))
//    //        Spring::throwRawException("help函数只能接受1个字符串类型参数");

//    //    std::string name = argument.str;

//    //    // 检查当前符号表中是否存在该名字
//    //    if(env.symbolTable.exist(name)){
//    //        Container result = env.symbolTable[name];
//    //        std::string str = name + "\n";
//    //        str += "  Type: " + result.getStrType() + "\n";
//    //        str += "  Value: " + result.getValueInformation() + "\n";
//    //        env.springIOHelper->print(str);
//    //        return true;
//    //    }

//    //    // 检查name是否是库的名字
//    //    if(env.springRuntimeLib.existLibrary(name)){
//    //        env.springIOHelper->onShowLibInfo({name});
//    //        return true;
//    //    }

//    //    // 检查name是否是库函数的名字
//    //    if(env.springRuntimeLib.existFunction(name)){
//    //        std::string funcDescription = env.springRuntimeLib.getFunctionDescription(name);
//    //        env.springIOHelper->print(funcDescription);
//    //        return true;
//    //    }

//    //    env.springIOHelper->print("Unknown symbol:" + name);
//    //    return false;
//    //}

//    //Container inputFunc(const std::deque<Container> &args, SpringRuntimeEnvironment &env)
//    //{
//    //    if(args.size() == 0)
//    //        return env.springIOHelper->input();

//    //    if(args.size() == 1){
//    //        Container c = args[0];
//    //        if(!c.isString())
//    //            Spring::throwRawException("input只接受一个字符串类型的参数");
//    //        return env.springIOHelper->input(c.toString());
//    //    }

//    //    Spring::throwRawException("input只接受0个参数，或一个字符串类型的参数");
//    //    return "";
//    //}

//    //Container lengthFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() != 1 || !args[0].isList()){
//    //        Spring::throwRawException("length函数只接受1个list类型参数");
//    //    }

//    //    int len = args[0].list.size();
//    //    return len;
//    //}

//    //Container notDefinedFunc(const std::deque<Container> &args)
//    //{
//    //    Spring::throwRawException("该库函数还未完成");
//    //}

//    //Container listRemoveFunc(const std::deque<Container> &args)
//    //{
//    //    if(args.size() != 2)
//    //        Spring::throwRawException("remove函数接受2个参数");

//    //    Container arg1 = args[0];
//    //    Container arg2 = args[1];

//    //    if (!arg1.isList())
//    //        Spring::throwRawException("remove函数第一个参数必须为list类型");
//    //    if(arg1.list.size()==0)
//    //        Spring::throwRawException("list为空");
//    //    if (!arg2.isNumber())
//    //        Spring::throwRawException("remove函数第二个参数必须为数字类型");

//    //    int realIndex = arg2.toInt();
//    //    realIndex = realIndex % arg1.list.size();
//    //    if(realIndex < 0)
//    //        realIndex += arg1.list.size();

//    //    auto iter = arg1.list.begin();
//    //    while (realIndex > 0) {
//    //        iter++;
//    //    }

//    //    arg1.list.erase(iter);
//    //    return arg1.list;
//    //}

//}
