#include "scrollerlight.h"

#include "python3.10/Python.h"
#include <iostream>

using namespace ScrollerController;

ScrollerLight::ScrollerLight() {}

ScrollerLight::~ScrollerLight() {}

void ScrollerLight::setBrightness(int value)
{
    Py_Initialize();
    // PyRun_SimpleString("import screen_brightness_control as screen");
    // PyRun_SimpleString("print 'hello'");

    // PyObject *pModule = PyImport_ImportModule(path.c_str());
    // if (!pModule) // 加载模块失败
    // {
    //     std::cout << "[ERROR] Python get module failed." << std::endl;
    //     return;
    // }
    // PyObject *setBrightness = PyObject_GetAttrString(pModule, "set_brightness");
    // if (!setBrightness || !PyCallable_Check(setBrightness)) // 验证是否加载成功
    // {
    //     std::cout << "[ERROR] Can't find funftion (set_brightness)" << std::endl;
    //     return;
    // }
    // std::cout << "[INFO] Get function (set_brightness) succeed." << std::endl;

    // 设置参数
    // PyObject *args = PyTuple_New(1);            // 1个参数
    // PyObject *arg1 = Py_BuildValue("i", value); // 参数一设为value
    // PyTuple_SetItem(args, 0, arg1);

    // 调用函数
    // PyObject *pRet = PyObject_CallObject(setBrightness, args);
    // PyRun_SimpleString("print 'hello'");

    Py_Finalize();
}