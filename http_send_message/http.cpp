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

#include <http.h>
#include <algorithm>

#if defined(WIN32) && defined(_MSC_VER)
#  define strcasecmp _stricmp
#else
#include <strings.h>
#endif

using namespace smart_http;
using namespace std;

http::http() :
    m_headers(),
    m_body("")
{
}

http::http(const http &other) :
    m_headers(other.m_headers),
    m_body(other.m_body)
{
}

http::http(http &&other)
{
    *this = std::move(other);
}

http& http::operator=(const http &other)
{
    if (this != &other) {
        m_headers = other.m_headers;
        m_body = other.m_body;
    }
    return *this;
}

http& http::operator=(http &&other)
{
  if (this != &other)
      *this = std::move(other);
  return *this;
}

void http::add_header(const string & name, const string & value)
{
    SetHeader(name, value);
}

string http::Header(const string & name) const
{
    auto it = m_headers.find(name);
    if (it != m_headers.end())
        return it->second;
    else
        return std::string();
}

http::HeaderCollection http::Headers() const
{
    return m_headers;
}

void http::RemoveHeader(const string & name)
{
    m_headers.erase(name);
}

void http::SetHeader(const string & name, const string & value)
{
    m_headers[name] = value;
}

http::~http()
{
}

const char* http::Body() const
{
    return m_body.c_str();
}

size_t http::BodySize() const
{
    return m_body.size();
}

bool http::HasBody() const
{
    return (m_body.size() != 0);
}

void http::SetBody(const string &body)
{
    m_body = body;
}

bool http::NocaseLess::operator() (const std::string & s1, const std::string & s2) const
{
    return strcasecmp(s1.c_str(), s2.c_str()) < 0;
}
