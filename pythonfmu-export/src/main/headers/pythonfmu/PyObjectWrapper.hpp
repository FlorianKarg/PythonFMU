
#ifndef PYTHONFMU_PYOBJECTWRAPPER_HPP
#define PYTHONFMU_PYOBJECTWRAPPER_HPP

#include <pythonfmu/thread_worker.hpp>

#include <cppfmu/cppfmu_common.hpp>

#include <Python.h>

namespace pythonfmu
{

class PyObjectWrapper
{

public:
    explicit PyObjectWrapper(const std::string& resources);

    void setupExperiment(double startTime);

    void enterInitializationMode();

    void exitInitializationMode();

    bool doStep(double currentTime, double steSize);

    void reset();

    void terminate();

    void getInteger(const cppfmu::FMIValueReference* vr, std::size_t nvr, cppfmu::FMIInteger* value) const;

    void getReal(const cppfmu::FMIValueReference* vr, std::size_t nvr, cppfmu::FMIReal* value) const;

    void getString(const cppfmu::FMIValueReference* vr, std::size_t nvr, cppfmu::FMIString* value) const;

    void getBoolean(const cppfmu::FMIValueReference* vr, std::size_t nvr, cppfmu::FMIBoolean* value) const;

    void setReal(const cppfmu::FMIValueReference* vr, std::size_t nvr, const cppfmu::FMIReal* value);

    void setInteger(const cppfmu::FMIValueReference* vr, std::size_t nvr, const cppfmu::FMIInteger* value);

    void setBoolean(const cppfmu::FMIValueReference* vr, std::size_t nvr, const cppfmu::FMIBoolean* value);

    void setString(const cppfmu::FMIValueReference* vr, std::size_t nvr, const cppfmu::FMIString* value);

    ~PyObjectWrapper();

private:
    PyObject* pModule_;
    PyObject* pClass_;
    PyObject* pInstance_;
};

} // namespace pythonfmu

#endif //PYTHONFMU_PYOBJECTWRAPPER_HPP
