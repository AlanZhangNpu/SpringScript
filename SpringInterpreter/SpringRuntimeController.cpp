#include "SpringRuntimeController.h"
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Spring.h"

namespace spr{

    SpringRuntimeController::SpringRuntimeController():
        runtimeMode(RUNTIME_PASS),
        isCurrentStepPassed(true)
    {}

    void SpringRuntimeController::setIOHelper(SpringIOHelper *h)
    {
        ioHelper = h;
    }

    void SpringRuntimeController::removeIOHelper()
    {
        ioHelper = nullptr;
    }

    void SpringRuntimeController::start()
    {
        runtimeMode = RUNTIME_PASS;
        isCurrentStepPassed = true;
    }

    void SpringRuntimeController::continueRunOneStep()
    {
        runtimeMode = RUNTIME_STEP_PASS;
        isCurrentStepPassed = false;
    }

    void SpringRuntimeController::pause()
    {
        runtimeMode = RUNTIME_PAUSE;
    }

    void SpringRuntimeController::continueRun()
    {
        runtimeMode = RUNTIME_PASS;
        isCurrentStepPassed = false;
    }

    void SpringRuntimeController::stop()
    {
        runtimeMode = RUNTIME_STOP;
    }

    bool SpringRuntimeController::isRun(int lineno)
    {
        bool isSendPauseMsg = false;

        while(true)
        {
            switch (runtimeMode) {
            case RUNTIME_PASS:
            {
                if(!isCurrentStepPassed){
                    isCurrentStepPassed = true;
                    return true;
                }

                // 检查断点
                auto it = std::find(breakPoints.begin(), breakPoints.end(), lineno);
                if(it == breakPoints.end())
                    return true;
                break;
            }
            case RUNTIME_STEP_PASS:
                if(!isCurrentStepPassed){
                    isCurrentStepPassed = true;
                    return true;
                }
                break;

            case RUNTIME_PAUSE:
                break;

            case RUNTIME_STOP:
            default:
                if(ioHelper != nullptr)
                    ioHelper->onStop(lineno);
                return false;
            }

            if(!isSendPauseMsg){
                if(ioHelper != nullptr)
                    ioHelper->onPause(lineno);
                isSendPauseMsg = true;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        return false;
    }

    void SpringRuntimeController::clearBreakPoints()
    {
        breakPoints.clear();
    }

    void SpringRuntimeController::printBreakPoints()
    {
//        qDebug() << breakPoints;
    }

    void SpringRuntimeController::toggleBreakPoint(int lineno)
    {
        auto it = std::find(breakPoints.begin(), breakPoints.end(), lineno);
        if(it != breakPoints.end())
            breakPoints.erase(it);
        else
            breakPoints.push_back(lineno);
    }

}
