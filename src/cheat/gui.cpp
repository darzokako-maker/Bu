void DrawModernMenu() {
    ImGui::SetNextWindowSize({ 650, 450 });
    ImGui::Begin("ZENITH", nullptr, ImGuiWindowFlags_NoDecoration);

    // SOL PANEL (SEKMELER)
    ImGui::BeginChild("Sidebar", { 150, 0 }, true);
    if (ImGui::Button("Aimbot", { 140, 45 })) currentTab = 0;
    if (ImGui::Button("Visuals", { 140, 45 })) currentTab = 1;
    if (ImGui::Button("Misc", { 140, 45 })) currentTab = 2;
    ImGui::EndChild();

    ImGui::SameLine();

    // SAĞ PANEL (ÖZELLİKLER)
    ImGui::BeginChild("Content", { 0, 0 }, true);
    if (currentTab == 1) { // Visuals
        ImGui::Text("ESP Ayarlari");
        ImGui::Separator();
        ImGui::Checkbox("Box ESP", &settings.box_esp);
        ImGui::Checkbox("Skeleton", &settings.skeleton);
        ImGui::SliderInt("Snaplines", &settings.snap_thickness, 1, 5);
    }
    ImGui::EndChild();

    ImGui::End();
}

