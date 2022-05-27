package coursework.entity;

import com.fasterxml.jackson.annotation.JsonIgnore;
import java.util.ArrayList;
import java.util.List;
import javax.persistence.*;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "BOOK_TYPES")
@NoArgsConstructor
public class BookType {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name = "name", nullable = false, length = 50)
  private String name;

  @Column(name = "cnt", nullable = false)
  private Integer count;

  @Column(name = "fine", nullable = false)
  private Integer fine;

  @Column(name = "day_count", nullable = false)
  private Integer dayCount;

  public BookType(String name, Integer count, Integer fine, Integer dayCount) {
    this.name = name;
    this.count = count;
    this.fine = fine;
    this.dayCount = dayCount;
  }

  @OneToMany(mappedBy = "type", cascade = CascadeType.ALL, orphanRemoval = true,
      fetch = FetchType.EAGER)
  @JsonIgnore
  private List<Book> books = new ArrayList<>();
}
