package com.example.myfirstapp

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageButton
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class PatientListAdapter internal constructor(
    context: Context,
    private val patientViewModel: PatientViewModel
) : RecyclerView.Adapter<PatientListAdapter.PatientViewHolder>() {

    private val inflater: LayoutInflater = LayoutInflater.from(context)
    private var patients = emptyList<Patient>()

    inner class PatientViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val patientItemFirstName: TextView = itemView.findViewById(R.id.firstName)
        val patientItemLastName: TextView = itemView.findViewById(R.id.lastName)
        val patientItemWeight: TextView = itemView.findViewById(R.id.weight)
        val patientItemHeight: TextView = itemView.findViewById(R.id.height)
        val patientItemFamilyName: TextView = itemView.findViewById(R.id.familyName)
        val patientItemSex: TextView = itemView.findViewById(R.id.sex)
        val patientItemProcedureNumber: TextView = itemView.findViewById(R.id.procedureNumber)
        val patientItemRecordDate: TextView = itemView.findViewById(R.id.recordDate)
    }

    init {
        patients = patientViewModel.allPatients.value ?: emptyList()
        println("Num of patients ${patients.size}")
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): PatientViewHolder {
        val itemView = inflater.inflate(R.layout.recyclerview_item, parent, false)
        return PatientViewHolder(itemView)
    }

    override fun onBindViewHolder(holder: PatientViewHolder, position: Int) {
        val current = patients[position]
        holder.patientItemFirstName.text = current?.name ?: ""
        holder.patientItemLastName.text = current?.lastName ?: ""
        holder.patientItemFamilyName.text = current?.familyName ?: ""
        holder.patientItemWeight.text = current?.weight ?: ""
        holder.patientItemHeight.text = current?.height ?: ""
        holder.patientItemSex.text = current?.sex ?: ""
        holder.patientItemProcedureNumber.text = current?.procedureNumber ?: ""
        holder.patientItemRecordDate.text = current?.recordDate ?: ""
        val deleteButton = holder.itemView.findViewById<ImageButton>(R.id.deleteButton)
        deleteButton.setOnClickListener {
            patientViewModel.delete(current)
            notifyDataSetChanged()
        }
    }

    internal fun setPatient(patients: List<Patient>) {
        this.patients = patients
        notifyDataSetChanged()
    }

    override fun getItemCount(): Int {
        return patients.size
    }
}

//override fun onCreate(savedInstanceState: Bundle?) {
    //super.onCreate(savedInstanceState)
   // val recyclerView = findViewById<RecyclerView>(R.id.recyclerview)
   // val adapter = PatientListAdapter(this)
   // recyclerView.adapter = adapter
   // recyclerView.layoutManager = LinearLayoutManager(this)
//}
