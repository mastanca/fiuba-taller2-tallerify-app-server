

#include "MongoDaoTest.h"
#include "../../src/api/domain/Track.h"
#include "../../src/api/dao/MongoDao.h"

void MongoDaoTest::testGetting() {
    MongoDao *dao = new MongoDao();
    std::string songLocation = "/music/sweet_home_alabama.mp3";
    int id = rand() + 1;
    Track track(id, songLocation);
    dao->saveTrack(&track);

    Track *gotTrack = dao->getTrack(track.getId());
    ASSERT_EQ(gotTrack->getId(), id);
    ASSERT_EQ(gotTrack->getFileLocation(), songLocation);
    delete gotTrack;
    delete dao;
}

void MongoDaoTest::testSaving() {
    MongoDao *dao = new MongoDao();
    std::string songLocation = "/music/paint_it_black.mp3";
    int id = rand() + 1;
    Track track(id, songLocation);
    ASSERT_NO_FATAL_FAILURE(dao->saveTrack(&track));
    delete dao;
}
