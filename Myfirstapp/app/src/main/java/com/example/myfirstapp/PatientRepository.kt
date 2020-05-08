package com.example.myfirstapp

import androidx.lifecycle.LiveData

// Declares the DAO as a private property in the constructor. Pass in the DAO
// instead of the whole database, because you only need access to the DAO
class PatientRepository(private val patientDao: PatientDao) {

    // Room executes all queries on a separate thread.
    // Observed LiveData will notify the observer when the data has changed.
    val allPatients: LiveData<List<Patient>> = patientDao.getPatients()

    suspend fun insert(patient: Patient) {
        patientDao.insert(patient)
    }

    suspend fun delete(patient: Patient) {
        patientDao.delete(patient)
    }
}