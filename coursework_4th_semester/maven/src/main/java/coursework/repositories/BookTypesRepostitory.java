package coursework.repositories;

import coursework.entity.BookType;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface BookTypesRepostitory extends JpaRepository<BookType, Long> {

}
