/*
 MIT License
 
 Copyright (c) 2019 Yuki Koyama
 
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

#include <filesystem-util.hpp>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>

namespace
{
    bool HasSuffix(const std::string& text, const std::string& suffix)
    {
        return text.size() >= suffix.size() && text.find(suffix, text.size() - suffix.size()) != std::string::npos;
    }
}

namespace filesystemutil
{
    std::vector<std::string> GetFileList(const std::string& dir_path,
                                         const std::string& suffix)
    {
        DIR* dir_ptr = opendir(dir_path.c_str());
        if (dir_ptr == nullptr)
        {
            throw std::runtime_error("Could not open the directory.");
        }
        dirent* dir_entry;
        std::vector<std::string> file_list;
        while ((dir_entry = readdir(dir_ptr)) != nullptr)
        {
            const std::string entry_name = dir_entry->d_name;
            if (HasSuffix(entry_name, suffix))
            {
                file_list.push_back(entry_name);
            }
        }
        closedir(dir_ptr);
        return file_list;
    }
}
