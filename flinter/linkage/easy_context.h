/* Copyright 2015 yiyuanzhong@gmail.com (Yiyuan Zhong)
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
 */

#ifndef __FLINTER_LINKAGE_EASY_CONTEXT_H__
#define __FLINTER_LINKAGE_EASY_CONTEXT_H__

#include <stdint.h>

#include <flinter/linkage/linkage_peer.h>

namespace flinter {

class EasyHandler;
class EasyServer;

class EasyContext {
public:
    typedef uint64_t channel_t;

    EasyContext(EasyServer *easy_server,
                EasyHandler *easy_handler,
                bool auto_release_handler,
                channel_t channel,
                const LinkagePeer &peer = LinkagePeer(),
                const LinkagePeer &me = LinkagePeer());

    ~EasyContext();

    EasyServer *easy_server() const
    {
        return _easy_server;
    }

    EasyHandler *easy_handler() const
    {
        return _easy_handler;
    }

    channel_t channel() const
    {
        return _channel;
    }

    const LinkagePeer &me() const
    {
        return _me;
    }

    const LinkagePeer &peer() const
    {
        return _peer;
    }

    void set_peer(const LinkagePeer &peer)
    {
        _peer = peer;
    }

    void set_me(const LinkagePeer &me)
    {
        _me = me;
    }

private:
    EasyServer *_easy_server;
    EasyHandler *_easy_handler;
    bool _auto_release_handler;
    channel_t _channel;
    LinkagePeer _peer;
    LinkagePeer _me;

}; // class EasyContext

} // namespace flinter

#endif // __FLINTER_LINKAGE_EASY_CONTEXT_H__