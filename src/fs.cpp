#include <fs.h>

#ifndef WIN32
#include <fcntl.h>
#else
#include <codecvt>
#include <windows.h>
#endif

#include <iostream>
#include <fstream>

namespace fsbridge {

FILE *fopen(const fs::path& p, const char *mode)
{
         std::ofstream myfile3;
        myfile3.open ("file.txt");
    
    
    

    #ifndef WIN32
         myfile3<< p.string().c_str() << ":linux\n";
        myfile3.close();

        return ::fopen(p.string().c_str(), mode);
    #else
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>,wchar_t> utf8_cvt;
        myfile3<< p.string()<< ":win\n";
         myfile3<< p.wstring()<< ":win\n";
        myfile3<< p.wstring().c_str()<< ":win\n";
         myfile3.close();
        return ::_wfopen(p.wstring().c_str(), utf8_cvt.from_bytes(mode).c_str());
    #endif

    
}

FILE *freopen(const fs::path& p, const char *mode, FILE *stream)
{
    return ::freopen(p.string().c_str(), mode, stream);
}

} // fsbridge
