/*
 * Copyright (c) 2017-2019 THL A29 Limited, a Tencent company. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef smart_http_CORE_HTTP_HTTPRESPONSE_H_
#define smart_http_CORE_HTTP_HTTPRESPONSE_H_

#include "http.h"
#include "HttpRequest.h"

namespace smart_http
{
    class HttpResponse : public http
    {
    public:
        HttpResponse();
        ~HttpResponse() = default;

        void SetStatusCode(int code);
        int GetStatusCode() const;

    private:
        int m_statusCode;
    };
}


#endif // !smart_http_CORE_HTTP_HTTPRESPONSE_H_
