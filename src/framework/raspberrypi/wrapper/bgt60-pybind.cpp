/**
 * @file        bgt60-pybind.cpp
 * @author      Infineon Technologies AG
 * @brief       Radar BGT60 Raspberry Pi Python Wrapper API
 * @copyright   Copyright (c) 2023 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "bgt60-rpi.hpp"
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

using namespace bgt60rpi;

PYBIND11_MODULE(bgt60_py, m) {
    
    // Wrapper for Bgt60Rpi class
    py::class_<Bgt60Rpi> bgt60rpi(m, "Bgt60Rpi"); 
        bgt60rpi
        .def(py::init<uint8_t, uint8_t>())
        .def("init", &Bgt60Rpi::init, "Initialization function")
        .def("deinit", &Bgt60Rpi::deinit, "De-initialize function")
        .def("getMotion", &Bgt60Rpi::getMotion, "Function to detect moving target")
        .def("getDirection", &Bgt60Rpi::getDirection, "Function to detect direction of \
                                                    moving target")
        .def("disableInterrupt", &Bgt60Rpi::disableInterrupt, "Disable interrupt")
        .def("enableInterrupt", static_cast< Error_t (Bgt60Rpi::*)(std::function<void(void)> &cback)>(&Bgt60Rpi::enableInterrupt), "Enable Interrupt");

    // Wrapping variables that are arguements to member functions and are defined as enum
    py::enum_<Error_t>(bgt60rpi, "Error_t", py::arithmetic())
        .value("OK", bgt60rpi::Error_t::OK)
        .value("INTF_ERROR",bgt60rpi::Error_t::INTF_ERROR)
        .value("CONF_ERROR",bgt60rpi::Error_t::CONF_ERROR)
        .value("READ_ERROR",bgt60rpi::Error_t::READ_ERROR)
        .value("WRITE_ERROR",bgt60rpi::Error_t::WRITE_ERROR)
        .export_values();

    py::enum_<bgt60rpi::Motion_t>(bgt60rpi, "Motion_t", py::arithmetic())
        .value("NO_MOTION", bgt60rpi::Motion_t::NO_MOTION)
        .value("MOTION", bgt60rpi::Motion_t::MOTION)
        .export_values();
    
    py::enum_<bgt60rpi::Direction_t>(bgt60rpi, "Direction_t", py::arithmetic())
        .value("NO_DIR", bgt60rpi::Direction_t::NO_DIR)
        .value("APPROACHING", bgt60rpi::Direction_t::APPROACHING)
        .value("DEPARTING", bgt60rpi::Direction_t::DEPARTING)
        .export_values();
        
}
