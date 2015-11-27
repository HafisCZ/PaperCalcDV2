#ifndef HTTPDOWNLOADREQUEST_H
#define HTTPDOWNLOADREQUEST_H

#include <string>

class HTTPDownloadRequest
{
    public:
        HTTPDownloadRequest();
        virtual ~HTTPDownloadRequest();
        std::string request(const std::string& url);
    protected:
    private:
        void *curl;
};

#endif // HTTPDOWNLOADREQUEST_H
