#include "HTTPDownloadRequest.h"

#include <iostream>
#include <sstream>

#include "C:\Program Files (x86)\msys\local\include\curl\curl.h"
#include "C:\Program Files (x86)\msys\local\include\curl\easy.h"
#include "C:\Program Files (x86)\msys\local\include\curl\curlbuild.h"

using namespace std;

size_t writeStream (void *twr, size_t tsize, size_t mem, void *stream)
{
    string data((const char*) twr, (size_t) tsize * mem);
    *((stringstream*) stream) << data << endl;
    return tsize * mem;
}

HTTPDownloadRequest::HTTPDownloadRequest()
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
}

HTTPDownloadRequest::~HTTPDownloadRequest()
{
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

string HTTPDownloadRequest::request(const std::string& url)
{
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    stringstream output;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeStream);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);

    CURLcode r = curl_easy_perform(curl);
    if (r != CURLE_OK) {
        return "-1";
    }

    return output.str();
}
