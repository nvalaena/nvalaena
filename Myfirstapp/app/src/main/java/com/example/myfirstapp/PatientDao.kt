package com.example.myfirstapp

import androidx.lifecycle.LiveData
import androidx.room.*

@Dao
interface PatientDao {

    @Query("SELECT * from patient_table ORDER BY Record_date desc")
    fun getPatients(): LiveData<List<Patient>>

    @Insert(onConflict = OnConflictStrategy.IGNORE)
    suspend fun insert(patient: Patient)

    @Query("DELETE FROM patient_table")
    suspend fun deleteAll()

    @Delete
    suspend fun delete(patient: Patient)
}