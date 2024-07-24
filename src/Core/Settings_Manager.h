/*
MIT License

Copyright (c) 2024 Natal'ya Pankina

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include "../Data_Models/User_Preferences.h"

// Управляет настройками приложения и сохранением пользовательских предпочтений.

class ASettings_Manager
{
public:
    ASettings_Manager(const std::string &file_name);
    ~ASettings_Manager();

    void Load_Settings();
    void Save_Settings();
    // std::string Get_Setting(const std::string &key) const;
    // void Set_Setting(const std::string &key, const std::string &value);

    AUser_Preferences Get_User_Preferences() const;

private:
    // std::string Settings_File;
    AUser_Preferences User_Preferences;
};
