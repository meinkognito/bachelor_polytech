package coursework.entity;

import javax.persistence.*;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "CLIENTS")
@NoArgsConstructor
public class Client {

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Long id;

  @Column(name = "first_name", nullable = false, length = 20)
  private String firstName;

  @Column(name = "last_name", nullable = false, length = 20)
  private String lastName;

  @Column(name = "pather_name", nullable = false, length = 20)
  private String patherName;

  @Column(name = "passport_seria", nullable = false, length = 20)
  private String passportSeria;

  @Column(name = "passport_num", nullable = false, length = 20)
  private String passportNumber;

  public Client(String firstName, String lastName, String patherName, String passportSeria,
      String passportNumber) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.patherName = patherName;
    this.passportSeria = passportSeria;
    this.passportNumber = passportNumber;
  }
}
