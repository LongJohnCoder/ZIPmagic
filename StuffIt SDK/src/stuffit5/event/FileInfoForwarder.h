// $Id: FileInfoForwarder.h,v 1.1.2.1 2001/07/05 23:32:36 serge Exp $
//
// Copyright (c)2000-2001 Aladdin Systems, Inc. All Rights Reserved.
// 245 Westridge Drive, Watsonville, CA 95076, USA
// http://www.aladdinsys.com/
// 1-831-761-6200
//
// This source code and specific concepts contained herein are confidential
// information and property of Aladdin Systems. Distribution is prohibited
// without written permission of Aladdin Systems.

#if !defined stuffit5_event_forwarder_FileInfoForwarder_h_included
#define stuffit5_event_forwarder_FileInfoForwarder_h_included

/** Forwarding event listener. Forwards engine events from virtual member functions
to C-style callback functions.

@author serge@aladdinsys.com
@version $Revision: 1.1.2.1 $, $Date: 2001/07/05 23:32:36 $
*/

#include "stuffit5/event/FileInfoListener.h"

namespace stuffit5 {
    namespace event {
        class FileInfoForwarder : public stuffit5::event::FileInfoListener {
        public:
            FileInfoForwarder(stuffit5_event_FileInfoListener_fileInfoEvent fileInfoEvent, stuffit5_Reader reader) :
                FileInfoListener(),
                reader(reader),
                callback(fileInfoEvent) {
                orphan(true);
            }

            virtual bool fileInfoEvent(uint32_t position) {
                return (*callback)(position, reader);
            }

        private:
            const stuffit5_Reader reader;
            const stuffit5_event_FileInfoListener_fileInfoEvent callback;
        };
    }
}

#endif

