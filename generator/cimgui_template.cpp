
#include "./imgui/imgui.h"
#include "./imgui/imgui_internal.h"
#include "cimgui.h"



#include "auto_funcs.cpp"


/////////////////////////////manual written functions
CIMGUI_API void igLogText(CONST char *fmt, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, 256, fmt, args);
    va_end(args);

    ImGui::LogText("%s", buffer);
}
CIMGUI_API void ImGuiTextBuffer_appendf(struct ImGuiTextBuffer *buffer, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    buffer->appendfv(fmt, args);
    va_end(args);
}

CIMGUI_API float igGET_FLT_MAX()
{
    return FLT_MAX;
}

CIMGUI_API ImVector_ImWchar* ImVector_ImWchar_create()
{
	return IM_NEW(ImVector<ImWchar>) ();
}

CIMGUI_API void ImVector_ImWchar_destroy(ImVector_ImWchar* self)
{
    IM_DELETE(self);
}

CIMGUI_API void ImVector_ImWchar_Init(ImVector_ImWchar* p)
{
	IM_PLACEMENT_NEW(p) ImVector<ImWchar>();
}
CIMGUI_API void ImVector_ImWchar_UnInit(ImVector_ImWchar* p)
{
	p->~ImVector<ImWchar>();
}

