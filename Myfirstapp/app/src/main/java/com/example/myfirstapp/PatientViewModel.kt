package com.example.myfirstapp

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

class PatientViewModel(application: Application) : AndroidViewModel(application) {

    private val repository: PatientRepository
    // Using LiveData and caching what getAlphabetizedWords returns has several benefits:
    // - We can put an observer on the data (instead of polling for changes) and only update the
    //   the UI when the data actually changes.
    // - Repository is completely separated from the UI through the ViewModel.
    val allPatients: LiveData<List<Patient>>

    init {
        val patientDao = PatientRoomDatabase.getDatabase(application, viewModelScope).PatientDao()
        repository = PatientRepository(patientDao)
        allPatients = repository.allPatients
    }

    /**
     * Launching a new coroutine to insert the data in a non-blocking way
     */
    fun insert(patient: Patient) = viewModelScope.launch(Dispatchers.IO) {
        repository.insert(patient)
    }

    fun delete(patient: Patient) = viewModelScope.launch(Dispatchers.IO) {
        repository.delete(patient)
    }


}