package coursework.repositories;

import coursework.entity.Journal;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface JournalRepostitory extends JpaRepository<Journal, Long> {

}
