

#include "TrackTest.h"
#include "../../src/api/domain/Track.h"

void TrackTest::testConstruction() {
    std::string songLocation = "/music/moonlight.mp3";
    Track track(5, songLocation);
    ASSERT_EQ(track.getId(), 5);
    ASSERT_EQ(track.getFileLocation(), songLocation);
}