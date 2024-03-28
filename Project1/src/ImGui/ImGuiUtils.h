#pragma once

#include <string>
#include <glm/glm.hpp>
#include <imgui_internal.h>
#include <imgui.h>


extern void DrawTransformVector3ImGui(std::string label, glm::vec3& values, float resetValue, float& columnWidth);
extern bool DrawDropDown(std::string label, int& currentItem, const char* const* items, int size);
extern bool DrawDragFloat(std::string label, float& value, float speed, float min, float max);
extern void DrawFloat(std::string label, float& value);
extern void DrawBool(std::string label, bool& value);