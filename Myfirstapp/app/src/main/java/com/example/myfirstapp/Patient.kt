package com.example.myfirstapp

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey
import java.util.*


@Entity(tableName = "patient_table")
class Patient(    @ColumnInfo(name = "name") var name: String,
                  @ColumnInfo(name = "last_name") var lastName: String,
                  @ColumnInfo(name = "family_name") var familyName: String,
                  @ColumnInfo(name = "Record_date") var recordDate: String,
                  @ColumnInfo(name = "Height") var height: String,
                  @ColumnInfo(name = "Weight") var weight: String,
                  @ColumnInfo(name = "Sex") var sex: String,
                  @ColumnInfo(name = "Number_of_procedure") var procedureNumber: String) {

    @PrimaryKey(autoGenerate = true)
    var id: Int = 0
    override fun toString(): String {
        return "Patient(name='$name', lastName='$lastName', familyName='$familyName', recordDate='$recordDate', height='$height', weight='$weight', sex='$sex', procedureNumber='$procedureNumber', id=$id)"
    }


}
