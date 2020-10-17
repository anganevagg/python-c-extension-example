#include <Python.h>
#include <stdio.h>

#if PY_MAJOR_VERSION >= 3
	#define IS_PY3K
#endif

static PyObject* helloworld(PyObject* self){
	return Py_BuildValue("s","hello in python by C extension");
}

static char helloWorldDocs[]="helloworld(): Any message you want to put here!!\n";

static PyMethodDef helloworld_funcs[] = {
	{"helloworld", (PyCFunction) helloworld,METH_NOARGS, helloWorldDocs},{NULL}
};

#ifdef IS_PY3K
static struct PyModuleDef helloworldmodule={
	PyModuleDef_HEAD_INIT,"helloworld",NULL,-1,helloworld_funcs
};

PyMODINIT_FUNC PyInit_helloworld(void){
	return PyModule_Create(&helloworldmodule);
}

#else
PyMODINIT_FUNC inithelloworld(void){
	(void) Py_InitModule3("helloworld",helloworld_funcs);
}
#endif
