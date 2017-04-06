

#include "TrackTest.h"
#include "../../src/api/domain/Track.h"
#include "base64/base64.h"

void TrackTest::testConstruction() {
    std::string song = "Little by little by little by little by...";
    std::string encoded = base64_encode(song);
    Track track(5, song, true);
    ASSERT_EQ(track.getId(), 5);
    ASSERT_EQ(track.getBase64EncodedBytes(), encoded);
}