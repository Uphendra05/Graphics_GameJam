
#include "ImGuiUtils.h"

void DrawTransformVector3ImGui(std::string label, glm::vec3& values, float resetValue, float& columnWidth)
{
	ImGui::PushID(label.c_str());

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, columnWidth);
	ImGui::Text(label.c_str());
	ImGui::NextColumn();

	ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

	ImGuiStyle& style = ImGui::GetStyle();

	float lineHeight = ImGui::GetFontSize() + style.FramePadding.y * 2;
	ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.1f, 0.15f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.2f, 0.2f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.1f, 0.15f, 1.0f));

	if (ImGui::Button("X", buttonSize))
	{
		values.x = resetValue;
	}

	ImGui::PopStyleColor(3);

	ImGui::SameLine();
	ImGui::DragFloat("##X", &values.x, 0.1f, 0, 0, "%0.2f");
	ImGui::PopItemWidth();
	ImGui::SameLine();


	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.7f, 0.3f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.8f, 0.3f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.2f, 0.7f, 0.2f, 1.0f));
	if (ImGui::Button("Y", buttonSize))
	{
		values.y = resetValue;
	}
	ImGui::PopStyleColor(3);


	ImGui::SameLine();
	ImGui::DragFloat("##Y", &values.y, 0.1f, 0, 0, "%0.2f");
	ImGui::PopItemWidth();
	ImGui::SameLine();

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1f, 0.25f, 0.8f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.35f, 0.9f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.25f, 0.8f, 1.0f));
	if (ImGui::Button("Z", buttonSize))
	{
		values.z = resetValue;
	}
	ImGui::PopStyleColor(3);

	ImGui::SameLine();
	ImGui::DragFloat("##Z", &values.z, 0.1f, 0, 0, "%0.2f");
	ImGui::PopItemWidth();

	ImGui::PopStyleVar();

	ImGui::Columns(1);

	ImGui::PopID();
}

bool DrawDropDown(std::string label, int& currentItem, const char* const* items, int size)
{
	bool initiated = false;

	ImGui::PushID(label.c_str());

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, 150);
	ImGui::Text(label.c_str());
	ImGui::NextColumn();

	if (ImGui::Combo(("###" + label).c_str(), &currentItem, items, size))
	{
		initiated = true;
	}

	ImGui::Columns(1);
	ImGui::PopID();

	
	return initiated;

}

bool DrawDragFloat(std::string label, float& value, float speed, float min, float max)
{
	bool initiated = false;

	ImGui::PushID(label.c_str());

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, 150);
	ImGui::Text(label.c_str());
	ImGui::NextColumn();

	if (ImGui::DragFloat(("###" + label).c_str(), &value, speed, min, max, "%.2f"))
	{
		initiated = true;
	}

	ImGui::Columns(1);

	ImGui::PopID();

	return initiated;
}

void DrawFloat(std::string label, float& value)
{

	ImGui::PushID(label.c_str());

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, 150);
	ImGui::Text(label.c_str());
	ImGui::NextColumn();

	if (ImGui::InputFloat(("###" + label).c_str(), &value, 0, 0, "%.2f"))
	{
	}

	ImGui::Columns(1);

	ImGui::PopID();

}

void DrawBool(std::string label, bool& value)
{

	ImGui::PushID(label.c_str());

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, 150);
	ImGui::Text(label.c_str());
	ImGui::NextColumn();

	if (ImGui::Checkbox(("###" + label).c_str(), &value))
	{
	}

	ImGui::Columns(1);

	ImGui::PopID();

}
