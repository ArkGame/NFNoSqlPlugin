/*
* This source file is part of ArkGameFrame
* For the latest info, see https://github.com/ArkGame
*
* Copyright (c) 2013-2017 ArkGame authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#include "AFCRedisDriver.h"
#include "SDK/Interface/AFIPluginManager.h"
#include "Interface/AFIRedisModule.h"

class AFCRedisModule : public AFIRedisModule
{
public:
    AFCRedisModule(AFIPluginManager* p);
    virtual ~AFCRedisModule();

    virtual bool Init();
    virtual bool Shut();
    virtual void Update();
    virtual bool PostInit();

    virtual bool ConnectRedis(const std::string& ip, const uint16_t port = 3306, const std::string& password = NULL_STR, const uint8_t db_index = 1);

    virtual ARK_SHARE_PTR<AFIRedisDriver> GetDriver()
    {
        return m_pRedisDriver;
    }

protected:
    ARK_SHARE_PTR<AFIRedisDriver> m_pRedisDriver;
};