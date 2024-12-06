#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
}
bool	Contact::isEmpty(void) const
{
	return (firstName.empty() || lastName.empty() || nickname.empty()
		|| phoneNumber.empty() || darkestSecret.empty());
}

void	Contact::setContact(const std::string &first, const std::string &last,
		const std::string &nick, const std::string &phone,
		const std::string &secret)
{
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

void	Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|" << std::setw(10) << truncateField(firstName) << "|" << std::setw(10) << truncateField(lastName) << "|" << std::setw(10) << truncateField(nickname) << std::endl;
}

void	Contact::displayDetails(void) const
{
	std::cout << "👤 First Name: " << firstName << std::endl;
	std::cout << "🖊️  Last Name: " << lastName << std::endl;
	std::cout << "🗣️  Nickname: " << nickname << std::endl;
	std::cout << "📞 Phone Number: " << phoneNumber << std::endl;
	std::cout << "🤫 Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::truncateField(const std::string &field)
{
	if (field.length() > 10)
	{
		return (field.substr(0, 9) + ".");
	}
	return (field);
}
