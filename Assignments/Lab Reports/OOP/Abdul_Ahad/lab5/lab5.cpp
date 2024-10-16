#include <iostream>
#include <string>

class JobApplicant
{
private:
    std::string name;
    std::string email;
    std::string phone;
    int yearsOfExperience;

public:
    JobApplicant(std::string name, std::string email, std::string phone, int yearsOfExperience)
        : name(std::move(name)), email(std::move(email)), phone(std::move(phone)), yearsOfExperience(yearsOfExperience)
    {
    }

    const std::string &getName() const
    {
        return name;
    }

    const std::string &getEmail() const
    {
        return email;
    }

    const std::string &getPhone() const
    {
        return phone;
    }

    int getYearsOfExperience() const
    {
        return yearsOfExperience;
    }
};

int main()
{
    // Create a job applicant
    JobApplicant applicant("SomeOne", "SomeOne@example.com", "555-1234", 5);


    std::cout << "Name: " << applicant.getName() << std::endl;
    std::cout << "Email: " << applicant.getEmail() << std::endl;
    std::cout << "Phone: " << applicant.getPhone() << std::endl;
    std::cout << "Years of experience: " << applicant.getYearsOfExperience() << std::endl;

    return 0;
}
