

#include "MongoDaoTest.h"
#include "../../src/api/domain/Track.h"
#include "../../src/api/dao/MongoDao.h"
#include "base64/base64.h"

void MongoDaoTest::testGetting() {
    MongoDao dao;
    std::string song = "Sweet home Alabama";
    int id = rand();
    Track track(id, song);
    dao.saveTrack(&track);

    Track *gotTrack = dao.getTrack(track.getId());
    ASSERT_EQ(gotTrack->getId(), id);
    ASSERT_EQ(base64_decode(gotTrack->getBase64EncodedBytes()), song);
    delete gotTrack;
}

void MongoDaoTest::testSaving() {
    MongoDao dao;
    std::string song = "I see a red door and I want to paint it black";
    int id = rand();
    Track track(id, song);
    ASSERT_NO_FATAL_FAILURE(dao.saveTrack(&track));
}
