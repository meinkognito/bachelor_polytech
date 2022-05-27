package coursework.web;

import coursework.entity.Journal;
import coursework.service.JournalService;
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
public class JournalController {

  private final JournalService journalService;

  @PostMapping("/addJournal")
  public Journal addJournal(@RequestBody Journal newJournal) {
    return journalService.addJournal(newJournal);
  }

  @GetMapping("/journals")
  public ResponseEntity<List<Journal>> getAllJournals() {
    return new ResponseEntity<>(journalService.listOfJournals(), HttpStatus.OK);
  }

  @GetMapping("/journal/{id}")
  public ResponseEntity<Journal> getJournal(@PathVariable("id") Long id) {
    try {
      return new ResponseEntity<>(journalService.getJournalById(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Journal not found");
    }
  }

  @PutMapping("/updateJournal/{id}")
  public ResponseEntity<Journal> updateJournal(@PathVariable Long id,
      @RequestBody Journal Journal) {
    try {
      return new ResponseEntity<>(journalService.updateJournal(id, Journal), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Journal not found");
    }
  }

  @DeleteMapping("/deleteJournal/{id}")
  public ResponseEntity<Journal> deleteJournal(@PathVariable Long id) {
    try {
      return new ResponseEntity<>(journalService.deleteJournal(id), HttpStatus.OK);
    } catch (NoSuchElementException e) {
      throw new ResponseStatusException(HttpStatus.NOT_FOUND, "Journal not found");
    }
  }
}
