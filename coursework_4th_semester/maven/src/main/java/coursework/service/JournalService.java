package coursework.service;

import coursework.entity.Journal;
import coursework.repositories.JournalRepostitory;
import java.util.List;
import java.util.NoSuchElementException;
import javax.transaction.Transactional;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

@Service
@AllArgsConstructor
public class JournalService {

  private final JournalRepostitory journalRepostitory;

  public List<Journal> listOfJournals() {
    return journalRepostitory.findAll();
  }

  public Journal getJournalById(Long id) throws NoSuchElementException {
    return journalRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no Journal"));
  }

  public Journal addJournal(Journal newJournal) {
    return journalRepostitory.save(newJournal);
  }

  public List<Journal> addJournals(List<Journal> journals) {
    return journalRepostitory.saveAll(journals);
  }

  @Transactional
  public Journal updateJournal(Long id, Journal journal) throws NoSuchElementException {
    Journal draft = journalRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no Journal"));

    draft.setBooks(journal.getBooks());
    draft.setClients(journal.getClients());
    draft.setBeginDate(journal.getBeginDate());
    draft.setEndDate(journal.getEndDate());
    draft.setReturnDate(journal.getReturnDate());
    return draft;
  }

  public Journal deleteJournal(Long id) throws NoSuchElementException {
    Journal journalToDelete = journalRepostitory.findById(id)
        .orElseThrow(() -> new NoSuchElementException("no Journal"));

    journalRepostitory.delete(journalToDelete);
    return journalToDelete;
  }
}
