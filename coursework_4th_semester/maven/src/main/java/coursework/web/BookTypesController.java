package coursework.web;

import coursework.entity.BookType;
import coursework.service.BookTypesService;
import java.util.List;
import java.util.NoSuchElementException;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

@RestController
@RequestMapping
@AllArgsConstructor
public class BookTypesController {

  private final BookTypesService bookTypesService;

  @PostMapping("/addBookType")
  public BookType addBookType(@RequestBody BookType bookType) {
    return bookTypesService.addBookType(bookType);
  }

  @GetMapping("/bookTypes")

  public ResponseEntity<List<BookType>> getAllBookTypes() {
    return new ResponseEntity<>(bookTypesService.listOfBookTypes(), HttpStatus.OK);
  }

  @GetMapping("/bookType/{id}")
  public ResponseEntity<BookType> getBookType(@PathVariable("id") Long id) {
    try {
      return new ResponseEntity<>(bookTypesService.getBookTypeById(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Book not found");
    }
  }

  @PutMapping("/updateBookType/{id}")
  public ResponseEntity<BookType> updateBook(@PathVariable Long id,
      @RequestBody BookType bookType) {
    try {
      return new ResponseEntity<>(bookTypesService.updateBookType(id, bookType), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "BookType not found");
    }
  }

  @DeleteMapping("/deleteBookType/{id}")
  public ResponseEntity<BookType> deleteBook(@PathVariable Long id) {
    try {
      return new ResponseEntity<>(bookTypesService.deleteBookType(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Book not found");
    }
  }
}
