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
#include "Settings_Manager.h"

#if need
std::map<std::string, std::string> settings;
//----------------------------------------------------------------------------------------------------
ASettings_Manager::ASettings_Manager(const std::string &file_name) : Settings_File(file_name)
{}
//----------------------------------------------------------------------------------------------------
ASettings_Manager::~ASettings_Manager()
{}
//----------------------------------------------------------------------------------------------------
void ASettings_Manager::Load_Settings()
{
    std::ifstream file(Settings_File);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, '=') && std::getline(iss, value))
                settings[key] = value;
        }
        file.close();
    } else
        std::cerr << "Unable to open settings file: " << Settings_File << std::endl;
}
//----------------------------------------------------------------------------------------------------
void ASettings_Manager::Save_Settings()
{
    std::ofstream file(Settings_File);
    if (file.is_open())
    {
        for (const auto& pair : settings)
            file << pair.first << "=" << pair.second << std::endl;

        file.close();
    } else
        std::cerr << "Unable to open settings file: " << Settings_File << std::endl;
}
//----------------------------------------------------------------------------------------------------
std::string ASettings_Manager::Get_Setting(const std::string &key) const
{
    auto it = settings.find(key);
    if (it != settings.end())
        return it->second;

    return "";
}
//----------------------------------------------------------------------------------------------------
void ASettings_Manager::Set_Setting(const std::string &key, const std::string &value)
{
    settings[key] = value;
}
#endif
//----------------------------------------------------------------------------------------------------