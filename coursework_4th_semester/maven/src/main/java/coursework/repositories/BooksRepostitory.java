package coursework.repositories;

import coursework.entity.Book;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface BooksRepostitory extends JpaRepository<Book, Long> {

}
