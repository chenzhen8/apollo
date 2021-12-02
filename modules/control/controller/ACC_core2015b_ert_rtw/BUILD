load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

CONTROL_COPTS = ['-DMODULE_NAME=\\"control\\"']


cc_library(
    name = "ACC_core2015b",
    srcs = ["ACC_core2015b.cc"],
    hdrs = ["ACC_core2015b.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":rt_zcfcn",
        ":rtGetInf",
        ":rt_nonfinite",
        ":ACC_core2015b_private",
        ":zero_crossing_types",
        ":rtwtypes",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "rtGetNaN",
    srcs = ["rtGetNaN.cc"],
    hdrs = ["rtGetNaN.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":rt_nonfinite",
    ],
)

cc_library(
    name = "rtGetInf",
    srcs = ["rtGetInf.cc"],
    hdrs = ["rtGetInf.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":rt_nonfinite",
    ],
)

cc_library(
    name = "rt_zcfcn",
    srcs = ["rt_zcfcn.cc"],
    hdrs = ["rt_zcfcn.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":solver_zc",
        ":rtwtypes",
        ":zero_crossing_types",
)

cc_library(
    name = "rt_nonfinite",
    srcs = ["rt_nonfinite.cc"],
    hdrs = ["rt_nonfinite.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":rtGetInf",
        ":rtGetNaN",
        ":rtwtypes",
    ],
)

cc_library(
    name = "ACC_core2015b_data",
    srcs = ["ACC_core2015b_data.cc"],
    copts = CONTROL_COPTS,
    deps = [
        ":ACC_core2015b_private",
        ":ACC_core2015b",
    ],
)

cc_library(
    name = "zero_crossing_types",
    hdrs = ["zero_crossing_types.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":rtwtypes",
    ],
)

cc_library(
    name = "ACC_core2015b_types",
    hdrs = ["ACC_core2015b_types.h"],
    copts = CONTROL_COPTS,
)

cc_library(
    name = "rtwtypes",
    hdrs = ["rtwtypes.h"],
    copts = CONTROL_COPTS,
)

cc_library(
    name = "ACC_core2015b_private",
    hdrs = ["ACC_core2015b_private.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":rtwtypes",
        ":zero_crossing_types",
    ],
)

cc_library(
    name = "solver_zc",
    hdrs = ["solver_zc.h"],
    copts = CONTROL_COPTS,
    deps = [
        ":rtwtypes",
    ],
)

cpplint()
