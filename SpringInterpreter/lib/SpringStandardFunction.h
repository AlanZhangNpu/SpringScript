#ifndef SPRINGSTANDARDFUNCTION_H
#define SPRINGSTANDARDFUNCTION_H

#include <vector>

#include "./core/object/SpringObject.h"
#include "SpringRuntimeEnvironment.h"

namespace spr {

    /***********************************************************************
    BASIC
    ***********************************************************************/

    SpringObjectPtr refCount(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr print(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr input(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr clear(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr clearall(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr type(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr import(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr easterEgg(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env);

    /***********************************************************************
    STRING
    ***********************************************************************/

    SpringObjectPtr string_lower(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr string_upper(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr string_find(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr string_sub(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr string_format(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    /***********************************************************************
    IO/FILE
    ***********************************************************************/

    SpringObjectPtr file_open(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr file_remove(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr file_rename(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr file_write(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr file_read(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr file_lines(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr file_close(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    /***********************************************************************
    LIST
    ***********************************************************************/

    SpringObjectPtr list_sort(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    /***********************************************************************
    MATH
    ***********************************************************************/

    SpringObjectPtr math_range(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment&env);

    SpringObjectPtr math_randu(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment&env);
    SpringObjectPtr math_randn(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_ones(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_zeros(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_eye(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_inv(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_pinv(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    SpringObjectPtr math_sin(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_cos(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_tan(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_asin(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_acos(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_atan(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_sinh(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_cosh(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_tanh(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    SpringObjectPtr math_ceil(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_floor(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    SpringObjectPtr math_deg(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_rad(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    SpringObjectPtr math_sqrt(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_exp(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_log(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    SpringObjectPtr math_max(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_min(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    SpringObjectPtr math_random(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_randomseed(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    SpringObjectPtr math_PI(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr math_HUGE(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

    /***********************************************************************
    OS
    ***********************************************************************/

    SpringObjectPtr os_clock(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env);
    SpringObjectPtr os_time(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env);
    SpringObjectPtr os_getenv(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);
    SpringObjectPtr os_system(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env);

}

#endif // SPRINGSTANDARDFUNCTION_H
