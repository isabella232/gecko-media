/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "VideoUtils.h"

#include "mozilla/SharedThreadPool.h"
#include "mozilla/TaskQueue.h"
#include "mozilla/Telemetry.h"
#include "nsIServiceManager.h"
#include "nsServiceManagerUtils.h"
#include "nsThreadUtils.h"

#include <functional>
#include <stdint.h>

namespace mozilla {


already_AddRefed<SharedThreadPool> GetMediaThreadPool(MediaThreadType aType)
{
  const char *name;
  switch (aType) {
    case MediaThreadType::PLATFORM_DECODER:
      name = "MediaPDecoder";
      break;
    default:
      MOZ_FALLTHROUGH_ASSERT("Unexpected MediaThreadType");
    case MediaThreadType::PLAYBACK:
      name = "MediaPlayback";
      break;
  }
  // FIXME: MediaPrefs::MediaThreadPoolDefaultCount() isn't yet available in the crate.
  return SharedThreadPool::
    Get(nsDependentCString(name), 4 /* MediaPrefs::MediaThreadPoolDefaultCount() */);
}


} // end namespace mozilla
