import source as System
import definitions as State


# Displaying a welcome screen #
System.WelcomeScreen()

while(State.PasswordTrialsNo != 0):
	# Asking for the selected mode (Admin Mode or User Mode) #
	State.Mode = System.AskForMode()
	## [Incorrect Entry] Handler ##
	while((State.Mode > '2') or (State.Mode < '0')):
		# Wrong system mode entry #
		System.ErrorHandler()
		# Asking for the selected mode (Admin Mode or User Mode) #
		State.Mode = System.AskForMode()
	## Terminate Handler ##
	if(State.Mode == State.Terminate):
		break
	## [Admin Mode] Handler ##
	elif(State.Mode == State.AdminMode):	
		# Asking for the system password #
		State.EnteredPassword = System.AskForPassword()
		## [Admin Mode - Incorrect Password] Handler ##
		while(State.EnteredPassword != State.SystemPassword):
			if(State.PasswordTrialsNo > 0):
				State.PasswordTrialsNo = State.PasswordTrialsNo - 1
				# Wrong password entry #
				System.ErrorHandler()
				# Asking for the system password #
				State.EnteredPassword = System.AskForPassword()
			else:
				# System is locked because a wrong password has been inserted 3 times #
				System.LockSystem()
				break
		## [Admin Mode - Correct Password] Handler ##
		if(State.EnteredPassword == State.SystemPassword):
			while(True):
				# Asking for the selected mode in Admin Mode (Manage Patients, Manage Doctors or Book an Appointment) #
				State.AdminModeSelector = System.AskForAdminMode()
				## [Admin Mode - Correct Password - Incorrect Entry] Handler ##
				while((State.AdminModeSelector > '3') or (State.AdminModeSelector < '0')):
					# Wrong system admin mode entry #
					System.ErrorHandler()
					# Asking for the selected mode in Admin Mode (Manage Patients, Manage Doctors or Book an Appointment) #
					State.AdminModeSelector = System.AskForAdminMode()
				## [Admin Mode - Correct Password - Terminate] Handler ##
				if(State.AdminModeSelector == State.Terminate):
					break
				## [Admin Mode - Correct Password - Manage Patients] Handler ##
				elif(State.AdminModeSelector == State.ManagePatients):
					while(True):
						# Asking for the selected operation in Admin Mode - Manage Patients (Add, Delete, Edit or Display a Patient) #
						State.PatientOption = System.AskForAdminModeManagePatients()
						## [Admin Mode - Correct Password - Manage Patients - Incorrect Patient Option] Handler ##
						# Checking if an appropriate patient option is selected or not #
						while((State.PatientOption > '5') or (State.PatientOption < '0')):
							# Wrong atient option entry #
							System.ErrorHandler()
							# Asking for the selected operation in Admin Mode - Manage Patients (Add, Delete, Edit or Display a Patient) #
							State.PatientOption = System.AskForAdminModeManagePatients()
						## [Admin Mode - Correct Password- Manage Patients - Terminate] Handler ##
						if(State.PatientOption == State.Terminate):
							break
						## [Admin Mode - Correct Password - Manage Patients - Add a Patient] Handler ##
						elif(State.PatientOption == State.AddPatient):
							System.AdminModeAddPatientHandler()
						## [Admin Mode - Correct Password - Manage Patients - Delete a Patient] Handler ##
						elif(State.PatientOption == State.DeletePatient):
							System.AdminModeDeletePatientHandler()
						## [Admin Mode - Correct Password - Manage Patients - Edit a Patient] Handler ##
						elif(State.PatientOption == State.EditPatient):
							System.AdminModeEditPatientHandler()
						## [Admin Mode - Correct Password - Manage Patients - Display a Patient] Handler ##
						elif(State.PatientOption == State.DisplayPatient):
							System.AdminModeDisplayPatientHandler()
						## [Admin Mode - Correct Password - Manage Patients - Display Patients] Handler ##
						elif(State.PatientOption == State.DisplayPatients):
							System.AdminModeDisplayPatientsHandler()
						else:
							# Wrong entry #
							System.ErrorHandler()
				## [Admin Mode - Correct Password - Manage Doctors] Handler ##
				elif(State.AdminModeSelector == State.ManageDoctors):
					while(True):
						# Asking for the selected operation in Admin Mode - Manage Doctors (Add, Delete, Edit or Display a Doctor) #
						State.DoctorOption = System.AskForAdminModeManageDoctors()
						## [Admin Mode - Correct Password - Manage Doctors - Incorrect Doctor Option] Handler ##
						# Checking if an appropriate doctor option is selected or not #
						while((State.DoctorOption > '5') or (State.DoctorOption < '0')):
							# Wrong doctor option entry #
							System.ErrorHandler()
							# Asking for the selected operation in Admin Mode - Manage Doctors (Add, Delete, Edit or Display a Doctor) #
							State.DoctorOption = System.AskForAdminModeManageDoctors()
						## [Admin Mode - Correct Password- Manage Doctors - Terminate] Handler ##
						if(State.DoctorOption == State.Terminate):
							break
						## [Admin Mode - Correct Password - Manage Doctors - Add a Doctor] Handler ##
						elif(State.DoctorOption == State.AddDoctor):
							System.AdminModeAddDoctorHandler()
						## [Admin Mode - Correct Password - Manage Doctors - Delete a Doctor] Handler ##
						elif(State.DoctorOption == State.DeleteDoctor):
							System.AdminModeDeleteDoctorHandler()
						## [Admin Mode - Correct Password - Manage Doctors - Edit a Doctor] Handler ##
						elif(State.DoctorOption == State.EditDoctor):
							System.AdminModeEditDoctorHandler()
						## [Admin Mode - Correct Password - Manage Doctors - Display a Doctor] Handler ##
						elif(State.DoctorOption == State.DisplayDoctor):
							System.AdminModeDisplayDoctorHandler()
						## [Admin Mode - Correct Password - Manage Doctors - Display Doctors] Handler ##
						elif(State.DoctorOption == State.DisplayDoctors):
							System.AdminModeDisplayDoctorsHandler()
						else:
							# Wrong entry #
							System.ErrorHandler()
				## [Admin Mode - Correct Password - Manage Appointments] Handler ##
				elif(State.AdminModeSelector == State.ManageAppointments):
					while(True):
						# Asking for the selected operation in Admin Mode - Manage Appointments (Book, Edit or Cancel an Appointment) #
						State.AppointmentOption = System.AskForAdminModeBookAppointment()
						## [Admin Mode - Correct Password - Manage Appointments - Incorrect Appointment Option] Handler ##
						# Checking if an appropriate appointment option is selected or not #
						while((State.AppointmentOption > '4') or (State.AppointmentOption < '0')):
							# Wrong appointment option entry #
							System.ErrorHandler()
							# Asking for the selected operation in Admin Mode - Manage Appointments (Book, Edit or Cancel an Appointment) #
							State.AppointmentOption = System.AskForAdminModeBookAppointment()
						## [Admin Mode - Correct Password- Manage Appointments - Terminate] Handler ##
						if(State.AppointmentOption == State.Terminate):
							break
						## [Admin Mode - Correct Password - Manage Appointments - Book an Appointment] Handler ##
						elif(State.AppointmentOption == State.BookAppointment):
							System.AdminModeBookAppointmentHandler()
						## [Admin Mode - Correct Password - Manage Appointments - Edit an Appointment] Handler ##
						elif(State.AppointmentOption == State.EditAppointment):
							System.AdminModeEditAppointmentHandler()
						## [Admin Mode - Correct Password - Manage Appointments - Cancel an Appointment] Handler ##
						elif(State.AppointmentOption == State.CancelAppointment):
							System.AdminModeCancelAppointmentHandler()
						## [Admin Mode - Correct Password - Manage Appointments - Display All Appointments] Handler ##
						elif(State.AppointmentOption == State.DisplayAppointments):
							System.AdminModeDisplayAppointmentsHandler()
						else:
							# Wrong entry #
							System.ErrorHandler()
				else:
					# Wrong entry #
					System.ErrorHandler()
		else:
			pass
	## [User Mode] Handler ##
	elif(State.Mode == State.UserMode):
		while(True):
			# Asking for the selected mode in User Mode (View Departments, View Doctors, View Patients, View One Patient or View an Appointment) #
			State.UserModeSelector = System.AskForUserMode()
			## [User ModeIncorrect Entry] Handler ##
			while((State.UserModeSelector > '5') or (State.UserModeSelector < '0')):
				# Wrong system user mode entry #
				System.ErrorHandler()
				# Asking for the selected mode in User Mode (view departments, view doctors, view patients, view info for one patient or view an appointment) #
				State.UserModeSelector = System.AskForUserMode()
			## [User Mode - Terminate] Handler ##
			if(State.UserModeSelector == State.Terminate):
				break
			## [User Mode - View Departments] Handler ##
			elif(State.UserModeSelector == State.Departments):
				System.UserModeViewDepartmentsHandler()
			## [User Mode - View Doctors] Handler ##
			elif(State.UserModeSelector == State.DoctorsInfo):
				System.UserModeViewDoctorsHandler()
			## [User Mode - View Patients] Handler ##
			elif(State.UserModeSelector == State.PatientsInfo):
				System.UserModeViewPatientsHandler()
			## [User Mode - View One Patient] Handler ##
			elif(State.UserModeSelector == State.OnePatientInfo):
				System.UserModeViewOnePatientHandler()
			## [User Mode - View an Appointment] Handler ##
			elif(State.UserModeSelector == State.AppointmentInfo):
				System.UserModeViewAppointmentHandler()
			else:
				# Wrong entry #
				System.ErrorHandler()
	else:
		# Wrong entry #
		System.ErrorHandler()
