#include "../include/Task.h"

int Task::nextId = 1;

Task::Task() {}

Task::Task(string type)
{
  this->id = Task::getNextId();
  this->type = type;
  this->title = "";
  this->description = "";
  this->order = 0;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::Task(string title, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = "";
  this->order = 0;

  std::time_t currentTime = std::time(nullptr);
  std::tm *timeInfo = std::localtime(&currentTime);

  deadline = *timeInfo;
  deadline.tm_year = 0;
  deadline.tm_mon = 0;
  deadline.tm_mday = 0;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::Task(string title, string description, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = description;
  this->order = 0;

  std::time_t currentTime = std::time(nullptr);
  std::tm *timeInfo = std::localtime(&currentTime);

  deadline = *timeInfo;
  deadline.tm_year = 0;
  deadline.tm_mon = 0;
  deadline.tm_mday = 0;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::Task(string title, string description, tm deadline, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = description;
  this->order = 0;
  this->deadline = deadline;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::~Task() {}

string Task::getId()
{
  return this->id;
}

string Task::getType()
{
  return this->type;
}

string Task::getTitle()
{
  return this->title;
}

void Task::setTitle(string title)
{
  this->title = title;
}

void Task::setOrder(int order)
{
  this->order = order;
}

int Task::getOrder()
{
  return this->order;
}

tm Task::getDeadline()
{
  return this->deadline;
}

void Task::setDeadline(tm date)
{
  this->deadline = date;
}

string Task::getDescription()
{
  return this->description;
}

void Task::setDescription(string description)
{
  this->description = description;
}

tm Task::getCreatedAt()
{
  return this->createdAt;
}

bool Task::operator==(const Task &task) const
{
  return this->id == task.id;
}

string Task::getNextId()
{
  return "T" + to_string(nextId++);
}