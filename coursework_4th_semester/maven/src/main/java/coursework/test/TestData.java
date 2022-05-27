package coursework.test;

import coursework.entity.*;
import coursework.repositories.UserRepository;
import coursework.service.*;
import java.time.LocalDate;
import java.time.Month;
import java.util.List;
import java.util.Set;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Component;

@Component
public class TestData implements CommandLineRunner {

  @Autowired
  UserRepository userRepository;

  @Autowired
  PasswordEncoder passwordEncoder;

  @Autowired
  BookTypesService bookTypesService;
  @Autowired
  BooksService booksService;
  @Autowired
  ClientsService clientsService;
  @Autowired
  JournalService journalService;

  @Override
  public void run(String... args) {
    BookType type1 = new BookType("Science Fiction", 50, 15, 30);
    BookType type2 = new BookType("Fairy tales", 40, 15, 30);
    BookType type3 = new BookType("Detective", 20, 15, 30);
    BookType type4 = new BookType("Horror", 15, 15, 30);

    bookTypesService.addBookTypes(List.of(type1, type2, type3, type4));

    Book book1 = new Book("1984", 7, type1);
    Book book2 = new Book("Sherlock Holmes", 10, type3);
    Book book3 = new Book("IT", 3, type4);
    Book book4 = new Book("Cinderella", 6, type2);

    booksService.addBooks(List.of(book1, book2, book3, book4));

    Client client1 = new Client(
        "Abraham",
        "Lincoln",
        "president of the US",
        "5555",
        "567890");

    Client client2 = new Client(
        "George",
        "Washington",
        "president of the US",
        "1234",
        "097856"
    );

    clientsService.addClients(List.of(client1, client2));

    Journal journal1 = new Journal(
        Set.of(book1, book2),
        Set.of(client1),
        LocalDate.of(1984, Month.AUGUST, 19),
        LocalDate.of(1984, Month.SEPTEMBER, 10),
        LocalDate.of(1984, Month.AUGUST, 31));

    Journal journal2 = new Journal(
        Set.of(book3, book4),
        Set.of(client2),
        LocalDate.of(2013, Month.AUGUST, 19),
        LocalDate.of(2013, Month.SEPTEMBER, 10),
        LocalDate.of(2013, Month.AUGUST, 31));

    journalService.addJournals(List.of(journal1, journal2));

    userRepository.save(new User("user",
        passwordEncoder.encode("p1$$w0rD"),
        List.of("ROLE_USER")));

    userRepository.save(new User("admin",
        passwordEncoder.encode("ADm1n_p1$$w0rD"),
        List.of("ROLE_ADMIN")));
  }
}
