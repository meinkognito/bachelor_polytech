package coursework.entity;

import java.util.HashSet;
import java.util.Set;
import javax.persistence.*;
import java.time.LocalDate;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
@Entity
@Table(name = "JOURNAL")
public class Journal {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @OneToMany(fetch = FetchType.EAGER)
  @JoinColumn(
      name = "book_id",
      foreignKey = @ForeignKey(
          name = "fk_journal_books"
      )
  )
  private Set<Book> books = new HashSet<>();

  @OneToMany(fetch = FetchType.EAGER)
  @JoinColumn(
      name = "client_id",
      foreignKey = @ForeignKey(
          name = "fk_journal_clients"
      )
  )
  private Set<Client> clients = new HashSet<>();

  @Column(name = "date_beg", nullable = false)
  private LocalDate beginDate;

  @Column(name = "date_end", nullable = false)
  private LocalDate endDate;

  @Column(name = "date_ret", nullable = false)
  private LocalDate returnDate;

  public Journal(Set<Book> books, Set<Client> clients, LocalDate beginDate,
      LocalDate endDate, LocalDate returnDate) {
    this.books = books;
    this.clients = clients;
    this.beginDate = beginDate;
    this.endDate = endDate;
    this.returnDate = returnDate;
  }
}
