package coursework.service;

import coursework.entity.BookType;
import coursework.repositories.BookTypesRepostitory;
import java.util.List;
import java.util.NoSuchElementException;
import javax.transaction.Transactional;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

@Service
@AllArgsConstructor
public class BookTypesService {

  private final BookTypesRepostitory bookTypesRepostitory;

  public List<BookType> listOfBookTypes() {
    return bookTypesRepostitory.findAll();
  }

  public BookType getBookTypeById(Long id) throws NoSuchElementException {
    return bookTypesRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no such type"));
  }

  public BookType addBookType(BookType bookType) {
    return bookTypesRepostitory.save(bookType);
  }

  public List<BookType> addBookTypes(List<BookType> bookTypes) {
    return bookTypesRepostitory.saveAll(bookTypes);
  }

  @Transactional
  public BookType updateBookType(Long id, BookType bookType) throws NoSuchElementException {
    BookType draft = bookTypesRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no such type"));

    draft.setName(bookType.getName());
    draft.setCount(bookType.getCount());
    draft.setFine(bookType.getFine());
    draft.setDayCount(bookType.getDayCount());
    return draft;
  }

  public BookType deleteBookType(Long id) throws NoSuchElementException {
    BookType typeToDelete = bookTypesRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no book"));

    bookTypesRepostitory.delete(typeToDelete);
    return typeToDelete;
  }
}
