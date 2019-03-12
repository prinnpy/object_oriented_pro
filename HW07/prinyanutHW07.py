# Name: Prinn Prinyanut
# Class: CSCI 2312
# Description: HW07 extra credits
# Due: May 3,2018

# import
import csv

# animal base class
class Animal(object):
	# constructor
	def __init__(self,name='',color=''):
		self.color = color
		self.name = name

	# read animal function
	def read_animal(self):
		print('read animal function')

	# print animal function
	def print_animal(self):
		print('print animal function')

# -----------------------------------------------------------------------------------------

# dog class
class Dog(Animal):

	# constructor
	def __init__(self,breed='',age=0,weight=0):
		self.breed = breed
		self.age = age
		self.weight = weight

	# read dog from file
	def read_animal(self):
		try:
			with open('Dog.csv') as csvfile:  # open csv
				next(csvfile)  # skip first line
				readCSV = csv.reader(csvfile,delimiter=',')
				# store into objects members
				for row in readCSV:
					self.name = row[0]
					self.breed = row[1]
					self.age = int(row[2])
					self.color = row[3]
					self.weight = int(row[4])
		except Exception as e:  # error handling
			print('\n-------------------------------------------------------------------------')
			print('DOG FILE ERROR! Please go fixed your dog csv file then rerun the program! Error: {}'.format(e))
			print('-------------------------------------------------------------------------\n')
			exit()

	# print dog objects
	def print_animal(self):
		print('\nDog:')
		print('----')
		print('Name: {}'.format(self.name))
		print('Color: {}'.format(self.color))
		print('Breed: {}'.format(self.breed))
		print('Age: {}'.format(self.age))
		print('Weight: {}'.format(self.weight))

	# subtract 10 from weight
	def weight_subtract_ten(self):
		self.weight -= 10

# -----------------------------------------------------------------------------------------

# fish class
class Fish(Animal):

	# constructor
	def __init__(self,habitat='',is_fresh_water=False,is_predator=False):
		self.habitat = habitat
		self.is_fresh_water = is_fresh_water
		self.is_predator = is_predator

	# read fish from file
	def read_animal(self):
		try:
			with open('Fish.csv') as csvfile:  # open csv
				next(csvfile)  # skip first line
				readCSV = csv.reader(csvfile,delimiter=',')
				# store into objects members
				for row in readCSV:
					self.name = row[0]
					self.color = row[1]
					self.is_fresh_water = self.return_bool(row[2])
					self.habitat = row[3]
					self.is_predator = self.return_bool(row[4])
		except Exception as e:  # error handling
			print('\n---------------------------------------------------------------------------')
			print('FISH FILE ERROR! Please go fixed your fish csv file then rerun the program! Error: {}'.format(e))
			print('---------------------------------------------------------------------------\n')
			exit()

	# print fish objects
	def print_animal(self):
		print('\nFish:')
		print('----')
		print('Name: {}'.format(self.name))
		print('Color: {}'.format(self.color))
		print('Habitat: {}'.format(self.habitat))
		print('Is FreshWater: {}'.format(self.is_fresh_water))
		print('Is Predator: {}'.format(self.is_predator))

	# convert string to bool
	def return_bool(self,string):
		if string == 'TRUE':
			return True
		elif string == 'FALSE':
			return False

# -----------------------------------------------------------------------------------------

# horse class
class Horse(Animal):

	# constructor
	def __init__(self,mane_color='',age=0,height=0):
		self.mane_color = mane_color
		self.age = age
		self.height = height

	# read horse from file
	def read_animal(self):
		try:
			with open('Horse.csv') as csvfile:  # open csv
				next(csvfile)  # skip first line
				readCSV = csv.reader(csvfile,delimiter=',')
				# store into objects members
				for row in readCSV:
					self.name = row[0]
					self.color = row[1]
					self.mane_color = row[2]
					self.age = int(row[3])
					self.height = int(row[4])
		except Exception as e:  # error handling
			print('\n-----------------------------------------------------------------------------')
			print('HORSE FILE ERROR! Please go fixed your horse csv file then rerun the program! Error: {}'.format(e))
			print('-----------------------------------------------------------------------------\n')
			exit()

	# print horse objects
	def print_animal(self):
		print('\nHorse:')
		print('-----')
		print('Name: {}'.format(self.name))
		print('Color: {}'.format(self.color))
		print('Mane Color: {}'.format(self.mane_color))
		print('Age: {}'.format(self.age))
		print('Height: {}'.format(self.height))

	# add 1 to height
	def height_add_one(self):
		self.height += 1

# -----------------------------------------------------------------------------------------

# lizard class
class Lizard(Animal):

	# constructor
	def __init__(self,habitat='',weight=0,is_protected=False):
		self.habitat = habitat
		self.weight = weight
		self.is_protected = is_protected

	# read lizard from file
	def read_animal(self):
		try:
			with open('Lizard.csv') as csvfile:  # open csv
				next(csvfile)  # skip first line
				readCSV = csv.reader(csvfile,delimiter=',')
				# store into objects members
				for row in readCSV:
					self.name = row[0]
					self.color = row[1]
					self.habitat = row[2]
					self.is_protected = self.return_bool(row[3])
					self.weight = int(row[4])
		except Exception as e:  # error handling
			print('\n-------------------------------------------------------------------------------')
			print('LIZARD FILE ERROR! Please go fixed your lizard csv file then rerun the program! Error: {}'.format(e))
			print('-------------------------------------------------------------------------------\n')
			exit()

	# print lizard objects
	def print_animal(self):
		print('\nLizard:')
		print('------')
		print('Name: {}'.format(self.name))
		print('Color: {}'.format(self.color))
		print('Habitat: {}'.format(self.habitat))
		print('Weight: {}'.format(self.weight))
		print('Is Protected: {}'.format(self.is_protected))

	# convert string to bool
	def return_bool(self,string):
		if string == 'TRUE':
			return True
		elif string == 'FALSE':
			return False

# -----------------------------------------------------------------------------------------

# monkey class
class Monkey(Animal):

	# constructor
	def __init__(self,home='',age=0,is_wild=False,is_endangered=False):
		self.home = home
		self.age = age
		self.is_wild = is_wild
		self.is_endangered = is_endangered

	# read monkey from file
	def read_animal(self):
		try:
			with open('Monkey.csv') as csvfile:  # open csv
				next(csvfile)  # skip first line
				readCSV = csv.reader(csvfile,delimiter=',')
				# store into objects members
				for row in readCSV:
					self.name = row[0]
					self.color = row[1]
					self.age = int(row[2])
					self.is_wild = self.return_bool(row[3])
					self.home = row[4]
					self.is_endangered = self.return_bool(row[5])
		except Exception as e:  # error handling
			print('\n-------------------------------------------------------------------------------')
			print('MONKEY FILE ERROR! Please go fixed your monkey csv file then rerun the program! Error: {}'.format(e))
			print('-------------------------------------------------------------------------------\n')
			exit()

	# toggle endangered
	def toggle_endangered(self):
		self.is_endangered = not self.is_endangered

	# convert string to bool
	def return_bool(self,string):
		if string == 'TRUE':
			return True
		elif string == 'FALSE':
			return False

	# print monkey objects
	def print_animal(self):
		print('\nMonkey:')
		print('------')
		print('Name: {}'.format(self.name))
		print('Color: {}'.format(self.color))
		print('Home: {}'.format(self.home))
		print('Age: {}'.format(self.age))
		print('Is Wild: {}'.format(self.is_wild))
		print('Is Endangered: {}\n'.format(self.is_endangered))

# -----------------------------------------------------------------------------------------

def main():
	# dog computations
	dog = Dog()
	dog.read_animal()
	dog.weight_subtract_ten()
	dog.print_animal()

	# fish computations
	fish = Fish()
	fish.read_animal()
	fish.print_animal()

	# horse computation
	horse = Horse()
	horse.read_animal()
	horse.height_add_one()
	horse.print_animal()

	# lizard computations
	lizard = Lizard()
	lizard.read_animal()
	lizard.print_animal()

	# monkey computations
	monkey = Monkey()
	monkey.read_animal()
	monkey.toggle_endangered()
	monkey.print_animal()

# -----------------------------------------------------------------------------------------

if __name__ == '__main__':
	# run main
	main()
