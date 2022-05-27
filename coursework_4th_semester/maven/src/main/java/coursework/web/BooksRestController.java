package coursework.web;

import java.util.List;
import coursework.entity.Book;
import coursework.service.BooksService;
import java.util.NoSuchElementException;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

@RestController
@RequestMapping
@AllArgsConstructor
public class BooksRestController {

  private final BooksService booksService;

  @PostMapping("/addBook")
  public Book addBook(@RequestBody Book newBook) {
    return booksService.addBook(newBook);
  }

  @GetMapping("/books")
  public ResponseEntity<List<Book>> getAllBooks() {
    return new ResponseEntity<>(booksService.listOfBooks(), HttpStatus.OK);
  }

  @GetMapping("/book/{id}")
  public ResponseEntity<Book> getBook(@PathVariable("id") Long id) {
    try {
      return new ResponseEntity<>(booksService.getBookById(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Book not found");
    }
  }

  @PutMapping("/updateBook/{id}")
  public ResponseEntity<Book> updateBook(@PathVariable Long id, @RequestBody Book book) {
    try {
      return new ResponseEntity<>(booksService.updateBook(id, book), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Book not found");
    }
  }

  @DeleteMapping("/deleteBook/{id}")
  public ResponseEntity<Book> deleteBook(@PathVariable Long id) {
    try {
      return new ResponseEntity<>(booksService.deleteBook(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Book not found");
    }
  }
}
