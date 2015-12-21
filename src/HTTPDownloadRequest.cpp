#include "HTTPDownloadRequest.h"

#include <iostream>
#include <sstream>

#include "C:\Users\Hafis\Desktop\curl\include\curl\curl.h"
#include "C:\Users\Hafis\Desktop\curl\include\curl\easy.h"
#include "C:\Users\Hafis\Desktop\curl\include\curl\curlbuild.h"

using namespace std;

size_t writeStream (void *twr, size_t tsize, size_t mem, void *stream)
{
    string data((const char*) twr, (size_t) tsize * mem);
    *((stringstream*) stream) << data << endl;
    return tsize * mem;
}

HTTPDownloadRequest::HTTPDownloadRequest()
{
    curl = curl_easy_init();
}

HTTPDownloadRequest::~HTTPDownloadRequest()
{
    curl_easy_cleanup(curl);
}

string HTTPDownloadRequest::request(const std::string& url)
{
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    stringstream output;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeStream);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);

    CURLcode r = curl_easy_perform(curl);
    if (r != CURLE_OK) {
        return "-1";
    }

    return output.str();
}
