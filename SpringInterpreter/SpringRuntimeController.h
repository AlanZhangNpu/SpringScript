#ifndef SPRINGRUNTIMECONTROLLER_H
#define SPRINGRUNTIMECONTROLLER_H
#include <vector>

namespace spr{

    class SpringIOHelper;

    //! Spring运行时控制器，可在四种模式下工作，分别为通过模式/单步通过模式/暂停模式/终止模式。
    //! Spring运行时控制器负责控制每条语句的运行标志，共三种运行标志：通过/等待/终止
    class __declspec(dllexport) SpringRuntimeController
    {
    public:
        SpringRuntimeController();

        void setIOHelper(SpringIOHelper * h);
        void removeIOHelper();

        void start();
        void pause();
        void continueRun();
        void continueRunOneStep();
        void stop();

        //! 判断某行是否可运行
        bool isRun(int lineno);

        //! 转换断点
        void toggleBreakPoint(int lineno);

        //! 清空所有断点
        void clearBreakPoints();

        //! 在控制台打印所有断点所在的行数（用来调试的）
        void printBreakPoints();

    private:
        enum SpringRuntimeMode{
            RUNTIME_PASS,
            RUNTIME_STEP_PASS,
            RUNTIME_PAUSE,
            RUNTIME_STOP
        };
        SpringIOHelper * ioHelper = nullptr;
        std::vector<int> breakPoints;
        SpringRuntimeMode runtimeMode;
        bool isCurrentStepPassed;
    };

}

#endif // SPRINGRUNTIMECONTROLLER_H
